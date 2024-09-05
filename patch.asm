0x80180f78:
u32 0x3c608051
0x80180fb0:
; lis r3, 0x8051 ; set Arena low to 0x80515CA0
; with inject at 0x80476000 gives us 0x9FCA0 bytes
u32 0x3c608051

; This will hook the main() function
0x8001B7f8:
b apply_lib_hooks

; main_tampoline
; This is an unused section of the dol that we use to store the trampoline for the main function.
0x802977D0:
u32 0x9421fff0 ; stwu r1,-0x10(r1)  ; First instruction from original FUN_8001b7f8() // todo find main()
u32 0x4bd84028 ; b main() + 4       ; branch to second instruction of FUN_8001b7f8()