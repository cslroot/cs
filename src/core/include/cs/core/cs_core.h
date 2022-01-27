#pragma once

#include <cs/core/core_common.h>

/**
 * @brief init cs.core
 *
 * @param argc number of argv. usually use args of main()
 * @param argv commandline args. usually use args of main()
 * @return true if initialization is succeed.
 */
DECL_CS_CORE bool cs_initialize(int argc, char** argv);
DECL_CS_CORE bool cs_terminate();
DECL_CS_CORE bool cs_is_initialized();
