/* Near miss of func_003B5088 with its file's own flags: tools/check.py reports 39 diff
   (the version it replaces: 154).
*/

/* US draft of func_003B5088 (rac3-uya-decomp func_003B4ED8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B5088 */
typedef struct { s32 x0; s32 x4; u8 b8; u8 p9[3]; void (*fnC)(void); } E_3B4ED8;
__asm__(".extern D_001D8960, 8");
__asm__(".extern D_001D8970, 4");
__asm__(".extern D_001D8948, 4");
__asm__(".extern D_001DA13C, 4");
__asm__(".extern D_001DA144, 4");
__asm__(".extern D_001DA138, 4");
__asm__(".extern D_001DA140, 4");
__asm__(".extern D_001D8944, 4");
__asm__(".extern D_001D8940, 4");
__asm__(".extern D_001D8974, 4");
__asm__(".extern D_001D8978, 4");
__asm__(".extern D_001D8998, 8");
__asm__(".extern D_001D8980, 8");
extern f32 D_001D8960[2];
extern f32 D_001D8970;
extern s32 D_001D8948;
extern s32 D_001DA13C;
extern s32 D_001DA144;
extern f32 D_001DA138;
extern f32 D_001DA140;
extern f32 D_001D8944;
extern f32 D_001D8940;
extern f32 D_001D8974;
extern f32 D_001D8978;
extern f32 D_001D8998[2];
extern f32 D_001D8980[2];
extern u8 *D_001D52FC_003B5088;
extern E_3B4ED8 D_00337640[];
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E8128(s32, s32);
extern void func_003A5748();
extern s32 func_003BB478();
extern void func_003BB480();
extern void func_003E73B0(void *p);
extern void func_003BB988();
extern void func_003BB948(s32);
void func_003B5088(void *arg0) {
    s32 i;
    s32 t;
    s32 found;
    s32 cmd;
    for (i = 0; i < 4; i++) {
        union { u32 i; f32 f; } u;
        u.i = 0x3BDA76D9;
        func_003E7770(i + 0x5B0002, 0.5f, D_001D8960[i]);
        func_003E85A8(i + 0x5B0002, D_001D8970, u.f);
    }
    t = *(s32 *)(D_001D52FC_003B5088 + 0x1C4);
    if (t & 0x4000) {
        found = 0;
        do {
            D_001D8948++;
            if (D_001D8948 >= 5) D_001D8948 = 0;
            if (D_00337640[D_001D8948].b8) found = 1;
        } while (found == 0);
        cmd = 3;
        goto send;
    } else if (t & 0x1000) {
        found = 0;
        do {
            D_001D8948--;
            if (D_001D8948 < 0) D_001D8948 = 4;
            if (D_00337640[D_001D8948].b8) found = 1;
        } while (found == 0);
        cmd = 3;
        goto send;
    } else if (t & 0x40) {
        if (D_00337640[D_001D8948].b8 && D_00337640[D_001D8948].fnC) {
            D_00337640[D_001D8948].fnC();
            cmd = 4;
send:
            func_003A5748(cmd, 0, 0);
        }
    } else if (!(t & 0x910)) {
        if (func_003BB478()) {
            func_003BB480();
            func_003E73B0(arg0);
        }
    }
    if (D_001DA13C == 0) {
        D_001DA13C = 1;
        D_001DA138 = D_001D8944;
    }
    if (D_001DA144 == 0) {
        D_001DA144 = 1;
        D_001DA140 = D_001D8940;
    }
    func_003E85A8(0xD0028, D_001D8974, D_001D8998[D_001D8948]);
    func_003E7770(0xD0028, D_001D8978, D_001D8980[D_001D8948]);
    for (i = 0; i < 5; i++) {
        if (D_00337640[i].b8) {
            func_003E8128(D_00337640[i].x0, 0x8066CCFF);
            if (i == D_001D8948) func_003E8128(D_00337640[i].x0, 0x66D6EEFA);
        } else {
            func_003E8128(D_00337640[i].x0, 0x80808080);
        }
    }
    func_003BB988();
    func_003BB948(0xD0028);
}
/* localdecomp:end func_003B5088 */
