# Copyright 2019-2021 Free Software Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Check that 'info types' produces the expected output for an inferior
# containing a number of different types.

# Match LINE against regexp OUTPUT_LINES[IDX].
proc match_line { line output_lines idx_name } {
    upvar $idx_name idx

    while { 1 } {
	if { $idx == [llength $output_lines] } {
	    # Ran out of regexps, bail out.
	    return -1
	}

	set re [lindex $output_lines $idx]
	if { $re == "--optional" } {
	    # Optional, get actual regexp.
	    set opt 1
	    incr idx
	    set re [lindex $output_lines $idx]
	} else {
	    # Not optional.
	    set opt 0
	}

	if { [regexp $re $line] } {
	    # Match.
	    incr idx
	    if { $idx == [llength $output_lines] } {
		# Last match, we're done.
		return 1
	    }
	    # Match found, keep looking for next match.
	    return 0
	} else {
	    # No match.
	    if { $idx == 0 } {
		# First match not found, just keep looking for first match.
		return 0
	    } elseif { $opt } {
		# Try next regexp on same line.
		incr idx
		continue
	    } else {
		# Mismatch, bail out.
		return -1
	    }
	}
	break
    }

    # Keep going.
    return 0
}

# Run 'info types' test, compiling the test file for language LANG,
# which should be either 'c' or 'c++'.
proc run_test { lang } {
    global testfile
    global srcfile
    global binfile
    global subdir
    global srcdir
    global compile_flags

    standard_testfile info-types.c

    if {[prepare_for_testing "failed to prepare" \
	     "${testfile}" $srcfile "debug $lang"]} {
	return -1
    }

    if ![runto_main] then {
	fail "can't run to main"
	return 0
    }

    if { $lang == "c++" } {
	set output_lines \
	    [list \
		 "98:\[\t \]+CL;" \
		 "42:\[\t \]+anon_struct_t;" \
		 "65:\[\t \]+anon_union_t;" \
		 "21:\[\t \]+baz_t;" \
		 "33:\[\t \]+enum_t;" \
		 "56:\[\t \]+union_t;" \
		 "52:\[\t \]+typedef enum {\\.\\.\\.} anon_enum_t;" \
		 "45:\[\t \]+typedef anon_struct_t anon_struct_t;" \
		 "68:\[\t \]+typedef anon_union_t anon_union_t;" \
		 "28:\[\t \]+typedef baz_t baz;" \
		 "31:\[\t \]+typedef baz_t \\* baz_ptr;" \
		 "27:\[\t \]+typedef baz_t baz_t;" \
		 "\[\t \]+double" \
		 "\[\t \]+float" \
		 "\[\t \]+int" \
		 "103:\[\t \]+typedef CL my_cl;" \
		 "38:\[\t \]+typedef enum_t my_enum_t;" \
		 "17:\[\t \]+typedef float my_float_t;" \
		 "16:\[\t \]+typedef int my_int_t;" \
		 "104:\[\t \]+typedef CL \\* my_ptr;" \
		 "54:\[\t \]+typedef enum {\\.\\.\\.} nested_anon_enum_t;" \
		 "47:\[\t \]+typedef anon_struct_t nested_anon_struct_t;" \
		 "70:\[\t \]+typedef anon_union_t nested_anon_union_t;" \
		 "30:\[\t \]+typedef baz_t nested_baz;" \
		 "29:\[\t \]+typedef baz_t nested_baz_t;" \
		 "39:\[\t \]+typedef enum_t nested_enum_t;" \
		 "19:\[\t \]+typedef float nested_float_t;" \
		 "18:\[\t \]+typedef int nested_int_t;" \
		 "62:\[\t \]+typedef union_t nested_union_t;" \
		 "--optional" "\[\t \]+unsigned int" \
		 ""]
    } else {
	set output_lines \
	    [list \
		 "52:\[\t \]+typedef enum {\\.\\.\\.} anon_enum_t;" \
		 "45:\[\t \]+typedef struct {\\.\\.\\.} anon_struct_t;" \
		 "68:\[\t \]+typedef union {\\.\\.\\.} anon_union_t;" \
		 "28:\[\t \]+typedef struct baz_t baz;" \
		 "31:\[\t \]+typedef struct baz_t \\* baz_ptr;" \
		 "21:\[\t \]+struct baz_t;" \
		 "\[\t \]+double" \
		 "33:\[\t \]+enum enum_t;" \
		 "\[\t \]+float" \
		 "\[\t \]+int" \
		 "38:\[\t \]+typedef enum enum_t my_enum_t;" \
		 "17:\[\t \]+typedef float my_float_t;" \
		 "16:\[\t \]+typedef int my_int_t;" \
		 "54:\[\t \]+typedef enum {\\.\\.\\.} nested_anon_enum_t;" \
		 "47:\[\t \]+typedef struct {\\.\\.\\.} nested_anon_struct_t;" \
		 "70:\[\t \]+typedef union {\\.\\.\\.} nested_anon_union_t;" \
		 "30:\[\t \]+typedef struct baz_t nested_baz;" \
		 "29:\[\t \]+typedef struct baz_t nested_baz_t;" \
		 "39:\[\t \]+typedef enum enum_t nested_enum_t;" \
		 "19:\[\t \]+typedef float nested_float_t;" \
		 "18:\[\t \]+typedef int nested_int_t;" \
		 "62:\[\t \]+typedef union union_t nested_union_t;" \
		 "56:\[\t \]+union union_t;" \
		 "--optional" "\[\t \]+unsigned int" \
		 ""]
    }

    set state 0
    set idx 0
    gdb_test_multiple "info types" "" {
	-re "\r\nAll defined types:" {
	    if { $state == 0 } { set state 1 } else { set state -1 }
	    exp_continue
	}
	-re "^\r\nFile .*[string_to_regexp $srcfile]:" {
	    if { $state == 1 } { set state 2 } else { set state -2 }
	    exp_continue
	}
	-re "^\r\nFile \[^\r\n\]*:" {
	    if { $state == 2 } { set state -4 }
	    exp_continue
	}
	-re -wrap "" {
	    if { $state == 3} {
		pass $gdb_test_name
	    } else {
		fail "$gdb_test_name (state == $state)"
	    }
	}
	-re "^\r\n(\[^\r\n\]*)(?=\r\n)" {
	    if { $state == 2 } {
		set line $expect_out(1,string)
		set res [match_line $line $output_lines idx]
		if { $res == 1 } {
		    set state 3
		} elseif { $res == -1 } {
		    set state -3
		}
	    }
	    exp_continue
	}
    }
}

run_test $lang
