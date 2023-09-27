#ifndef TEST_H
#define TEST_H

// intended to run on 1 hart
// expected result is printed along with the result
extern void printf_test();

// intended to run on 3 harts
// first print should be all mixed up while second one is all A's together
// all B's together and all C's together in random order. this checks that use
// of spinlock actually helps
extern void spinlock_test();

// unprivileged risc-v isa:
//     With the addition of the C extension, no instructions can raise
//     instruction-address-misaligned exceptions.
// test is successful if execution continues
extern void exc_instruction_address_misaligned_test();

// qemu-virt supports misaligned loads (tested)
// test is successful if execution continues
extern void exc_load_address_misaligned_test();

// qemu-virt supports misaligned stores (tested)
// no ZAM extension means we can still trigger this exception with amo instrs
extern void exc_store_or_amo_address_misaligned_test();

// others just trigger the appropriate exception
extern void exc_instruction_access_fault_test();
extern void exc_illegal_instruction_test();
extern void exc_breakpoint_test();
extern void exc_load_access_fault_test();
extern void exc_store_or_amo_access_fault_test();

#endif // TEST_H