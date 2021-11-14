; .section .text  // place in executable section

; .global addf     // mark add as global symbol for linking
; .type addf @function

.section .text

.globl asmAdd
asmAdd:
    add a0, a0, a1
    ret


.globl asmSwap
asmSwap:
    lw t0, 0(a0)
    lw t1, 0(a1)
    sw t0, 0(a1)
    sw t1, 0(a0)
    ret