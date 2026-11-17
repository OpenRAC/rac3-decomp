/* func_L01_0049BEC0: 7 diff in L01_0049BE80.c (its own flags). Only the loop exit test of case 1 differs:
   gcc loads the $gp index into $v0 and the list word into $v0 again, retail uses $v1 for both (the same
   registers as the loop body). for/while/break/do-while and index-type forms all give 7 (or 9).
   Uses the typedef E_498978 of L01_0049BE80.c (check.py adds the file's context). */
extern s32 D_L01_001D940C;
extern E_498978 D_L01_002EBED8[];
extern u8 D_L01_001EA7C0[];
extern void func_00392B20(void *, s32);
extern void func_L01_0049BE80(void);
extern s32 func_L01_0049D590(void);
extern s32 func_L01_0049C630(void);
extern void func_L01_0047DAD0();
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_00517748();
extern void *func_L01_0049B550();
extern void func_L01_00516090_0049BEC0(void *p);

void func_L01_0049BEC0(void *a0) {
    s32 i;

    if (!D_L01_002EBED8[D_L01_001D940C].x14) {
        return;
    }
    switch (D_L01_002EBED8[D_L01_001D940C].x10) {
    case 0:
        func_00392B20(D_L01_001EA7C0, D_L01_002EBED8[D_L01_001D940C].xC);
        return;
    case 1:
        for (i = 0; ((s32 *)D_L01_002EBED8[D_L01_001D940C].xC)[i] != 0; i++) {
            func_00392B20(D_L01_001EA7C0, ((s32 *)D_L01_002EBED8[D_L01_001D940C].xC)[i]);
        }
        return;
    case 2:
        return;
    case 3:
        func_L01_0049BE80();
        return;
    case 4:
    default:
        if (!D_L01_002EBED8[D_L01_001D940C].x14) {
            return;
        }
        switch (D_L01_002EBED8[D_L01_001D940C].x0) {
        case 0x1C4:
            func_L01_00517748(func_L01_0049D590());
            func_L01_00516090_0049BEC0(a0);
            break;
        case 0x1C3:
            func_L01_00517748(func_L01_0049C630());
            func_L01_00516090_0049BEC0(a0);
            break;
        case 0x1C0:
            func_00392B20(D_L01_001EA7C0, 2);
            func_L01_0047DAD0(8);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090_0049BEC0(func_L01_0049B550());
            break;
        }
        return;
    }
}
