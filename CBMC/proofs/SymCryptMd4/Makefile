HARNESS_ENTRY = harness
HARNESS_FILE = SymCryptMd4_harness

# This should be a unique identifier for this proof, and will appear on the
# Litani dashboard. It can be human-readable and contain spaces if you wish.
PROOF_UID = SymCryptMd4

DEFINES +=
INCLUDES +=

REMOVE_FUNCTION_BODY +=
UNWINDSET +=

PROOF_SOURCES += $(PROOFDIR)/$(HARNESS_FILE).c
PROJECT_SOURCES += $(SRCDIR)/lib/md4.c
PROJECT_SOURCES += $(SRCDIR)/lib/env_linuxUserMode.c
PROJECT_SOURCES += $(SRCDIR)/lib/libmain.c
PROJECT_SOURCES += $(SRCDIR)/lib/hash.c

CBMC_DEFAULT_UNWIND ?=
CBMC_FLAG_MALLOC_MAY_FAIL ?= 
CBMC_FLAG_MALLOC_FAIL_NULL ?= 
CBMC_FLAG_BOUNDS_CHECK ?= --bounds-check
CBMC_FLAG_CONVERSION_CHECK ?= 
CBMC_FLAG_MEMORY_LEAK_CHECK ?= --memory-leak-check
CBMC_FLAG_MEMORY_CLEANUP_CHECK ?= --memory-cleanup-check
CBMC_FLAG_DIV_BY_ZERO_CHECK ?= 
CBMC_FLAG_FLOAT_OVERFLOW_CHECK ?= 
CBMC_FLAG_NAN_CHECK ?= 
CBMC_FLAG_POINTER_CHECK ?= --pointer-check
CBMC_FLAG_POINTER_OVERFLOW_CHECK ?= 
CBMC_FLAG_POINTER_PRIMITIVE_CHECK ?= 
CBMC_FLAG_SIGNED_OVERFLOW_CHECK ?= 
CBMC_FLAG_UNDEFINED_SHIFT_CHECK ?= 
CBMC_FLAG_UNSIGNED_OVERFLOW_CHECK ?= 
CBMC_FLAG_UNWINDING_ASSERTIONS ?= --unwinding-assertions
CBMC_OBJECT_BITS ?= 9
# If this proof is found to consume huge amounts of RAM, you can set the
# EXPENSIVE variable. With new enough versions of the proof tools, this will
# restrict the number of EXPENSIVE CBMC jobs running at once. See the
# documentation in Makefile.common under the "Job Pools" heading for details.
# EXPENSIVE = true

# If you require access to a file-local ("static") function or object to conduct
# your proof, set the following (and do not include the original source file
# ("lib/md4.c") in PROJECT_SOURCES).
# REWRITTEN_SOURCES = $(PROOFDIR)/<__SOURCE_FILE_BASENAME__>.i
# include ../Makefile.common
# $(PROOFDIR)/<__SOURCE_FILE_BASENAME__>.i_SOURCE = $(SRCDIR)/lib/md4.c
# $(PROOFDIR)/<__SOURCE_FILE_BASENAME__>.i_FUNCTIONS = foo bar
# $(PROOFDIR)/<__SOURCE_FILE_BASENAME__>.i_OBJECTS = baz
# Care is required with variables on the left-hand side: REWRITTEN_SOURCES must
# be set before including Makefile.common, but any use of variables on the
# left-hand side requires those variables to be defined. Hence, _SOURCE,
# _FUNCTIONS, _OBJECTS is set after including Makefile.common.

include ../Makefile.common
