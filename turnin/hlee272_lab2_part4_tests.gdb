# Test file for "Lab2"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 47 PINB: 47 PINC: 47 => PORTD: 0x8D" 
# Set inputs
setPINA 0x2F
setPINB 0x2F
setPINC 0x2F
# Continue for several ticks
continue 2
# Set expect values
expectPORTD 0x8D
# Check pass/fail
checkResult

# Add tests below
test "PINA: 30  PINB: 20  PINC: 120 => PORTD: 0xAB"
setPINA 0x1E
setPINB 0x14
setPINC 0x78
continue 2
expectPORTD 0xAB
checkResult

test "PINA: 0 PINB: 0 PINC: 0 => PORTD = 0x00"
setPINA 0x00
setPINB 0x00
setPINC 0x00
continue 2 
expectPORTD 0x00
checkResult

test "PINA: 0 PINB: 0 PINC: 120 => PORTD: 0x7A"
setPINA 0x00
setPINB 0x00
setPINC 0x78
continue 2
expectPORTD 0x7A
checkResult
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
