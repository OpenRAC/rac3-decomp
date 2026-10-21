/* US draft of func_003A7480 (rac3-uya-decomp func_003A2028, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A7480 */
typedef struct { u8 pad[0x44]; s16 h44; u8 pad2[0x15A]; s32 tbl[1]; } S_225780_3A2028;
typedef struct { u8 pad[0x28]; s32 f28; } E_3A2028;
extern S_225780_3A2028 D_00225700_3A2028;
extern E_3A2028 *D_001DA49C_3A2028;
extern s32 D_001D5B94;
extern s32 D_001D5B90;
extern s32 D_001D9BC4;
extern s32 D_001D9BC8;
extern s32 D_001D9D1C;
extern void func_003A91D0();
extern void func_003A9150();
extern void func_003923D0();
extern void func_00392748();
extern void func_003922B8();
extern void func_0039C410();
extern void func_003861F0();
extern void func_003C2DC0();
extern void func_00387F68();
extern void func_003A3B70();
extern s32 func_003A6890();
extern void func_00392350();
extern void func_00388AF8();
extern void func_003A92F0();
extern void func_003A72A0();
s32 func_003A7480(void) {
    E_3A2028 *t;
    E_3A2028 *e;
    s32 i;
    s32 r;
    s32 s;
    if (((s32 (*)())func_003A6F28)() == 0) return 1;
    t = D_001DA49C_3A2028;
    for (i = 0; i < D_00225700_3A2028.h44; i++) {
        do { e = (E_3A2028 *)D_00225700_3A2028.tbl[i]; } while (0);
        if (e != 0 && t != e) {
            do { e->f28 = (s32)t; t = e; } while (0);
        }
    }
    D_001D5B94 = 2;
    do {
        func_003A91D0();
        func_003A9150();
        func_003923D0();
        func_00392748(1);
        func_003922B8();
        func_0039C410();
        func_003861F0();
        func_003C2DC0();
        func_00387F68();
        D_001D9D1C = -1;
        func_003A3B70();
        r = func_003A6890();
        func_00392350(0);
        D_001D9BC4 = 0x131;
        func_00388AF8(0);
        s = D_001D5B90;
        if (s != -2) {
            D_001D5B94 = s;
            D_001D5B90 = -2;
        }
        func_003A92F0(1);
        func_12C908(0);
        D_001D9BC8 = D_001D9BC8 + 1;
    } while (D_001D5B94 == 2);
    D_001D5B94 = 0;
    func_003A72A0();
    return r;
}
/* localdecomp:end func_003A7480 */
