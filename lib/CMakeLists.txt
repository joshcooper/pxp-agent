cmake_minimum_required(VERSION 3.2.2)

# Set include directories

include_directories(
    inc
    ${LEATHERMAN_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    ${HORSEWHISPERER_INCLUDE_DIRS}
    ${INIH_INCLUDE_DIRS}
    ${cpp-pcp-client_INCLUDE_DIR}
)

set(LIBRARY_COMMON_SOURCES
    src/action_request.cc
    src/agent.cc
    src/configuration.cc
    src/pxp_connector.cc
    src/external_module.cc
    src/module.cc
    src/modules/echo.cc
    src/modules/ping.cc
    src/modules/status.cc
    src/request_processor.cc
    src/pxp_schemas.cc
    src/thread_container.cc
)

if (UNIX)
    set(LIBRARY_STANDARD_SOURCES
        src/util/posix/daemonize.cc
        src/util/posix/pid_file.cc
        src/util/posix/process.cc
        src/configuration/posix/configuration.cc
    )
endif()

if (WIN32)
    set(LIBRARY_STANDARD_SOURCES
        src/util/windows/daemonize.cc
        src/util/windows/process.cc
        src/configuration/windows/configuration.cc
    )
endif()

set (LIBS
    ${cpp-pcp-client_LIBRARY}
    ${Boost_LIBRARIES}
    ${OPENSSL_SSL_LIBRARY}
    ${OPENSSL_CRYPTO_LIBRARY}
    ${LEATHERMAN_LIBRARIES}
)

add_library(libpxp-agent STATIC ${LIBRARY_COMMON_SOURCES} ${LIBRARY_STANDARD_SOURCES})
target_link_libraries(libpxp-agent ${LIBS})
set_target_properties(libpxp-agent PROPERTIES PREFIX "" IMPORT_PREFIX "")

install(TARGETS libpxp-agent
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

add_subdirectory(tests)
