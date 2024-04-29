cmake_minimum_required(VERSION 3.28)

function(yg_add_resource_folder)
    cmake_parse_arguments(
        PARSE_ARGV
        0
        YG
        ""
        "DESTINATION"
        "TARGETS;RESOURCES")
    message(
        STATUS
            "Targets: ${YG_TARGETS}, Dest: ${YG_DESTINATION}, Res: ${YG_RESOURCES}"
        )

    foreach(target IN LISTS YG_TARGETS)
        if(NOT TARGET ${target})
            message(FATAL_ERROR "Unexisting target: ${target}")
        endif()
        foreach(resource IN LISTS YG_RESOURCES)
            if(NOT EXISTS ${resource})
                message(FATAL_ERROR "Resource `${resource}` doesnt exist")
            endif()

            get_filename_component(res_name ${resource} NAME)
            set(destination $<TARGET_FILE_DIR:${target}>/${YG_DESTINATION})
            add_custom_command(
                TARGET ${target}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory ${destination}
                COMMAND
                    ${CMAKE_COMMAND} -E create_symlink ${resource}
                    ${destination}/${res_name} DEPENDS
                    ${destination}/${res_name}
                COMMENT
                    "symbolic link resources folder from ${CMAKE_CURRENT_SOURCE_DIR}/data => ${CMAKE_CURRENT_BINARY_DIR}/res"
                )
        endforeach()

    endforeach()

endfunction()
