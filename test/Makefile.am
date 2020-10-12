TESTS = check_morse
check_PROGRAMS = check_morse
check_morse_SOURCES = check_morse.c $(top_builddir)/src/lib/alphanumeric-morse.h
check_morse_CFLAGS = @CHECK_CFLAGS@ -I $(top_builddir)/src/lib 
check_morse_LDADD = @CHECK_LIBS@ $(top_builddir)/src/lib/libalphanumeric_morse.a
