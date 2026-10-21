/* US draft of func_0013B330 (rac3-uya-decomp func_0013B330, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0013B330 */
extern u8 D_001D551D;
extern char D_001D4D90[];
extern char D_001D4D98[];
extern void func_001260D0(void);
extern s32 func_0011B9A0(char *, char *, s32);
extern s32 func_0011B610(char *, char *);
extern void func_0013B208(char *);
extern void *func_0013AFF8(void);
extern void func_0011F0A0(s32);
extern void func_00381280(void);

void func_0013B330(s32 argc, char **argv) {
    void (*fn)(void);

    func_001260D0();
    D_001D551D = 0;
    if (argc > 0) {
        do {
            if (func_0011B9A0(*argv, D_001D4D90, 5) == 0) {
                func_0013B208(*argv + 5);
                D_001D551D++;
            } else if (func_0011B610(*argv, D_001D4D98) == 0) {
                D_001D551D++;
            }
            argv++;
        } while (--argc != 0);
    }
    fn = func_00381280;
    for (;;) {
        fn();
        fn = (void (*)(void))func_0013AFF8();
        func_0011F0A0(0);
        func_0011F0A0(2);
    }
}
/* localdecomp:end func_0013B330 */
