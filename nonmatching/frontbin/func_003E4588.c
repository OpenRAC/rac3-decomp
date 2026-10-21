/* Near miss of func_003E4588 with its file's own flags: tools/check.py reports 433 diff
   (the version it replaces: 442).
   What differs: float constants: retail builds all 22 of them inline (`lui $at`/`ori`/`mtc1`);
   with the file's flags gcc emits `li.s`, and the default assembler (`bin/ee-as.exe`) expands
   `li.s` inline only when the constant's low 16 bits are zero, so every other constant goes
   into a `.lit4` pool and becomes `lwc1 $f, off($gp)` - only Ps2EeAs (`@ps2as`, what the US
   project used for this function) expands `li.s` inline, and file 0x003E1340 has no `@ps2as`.
   Second difference: `D_001DA7E8` is `lui`/`addiu` in retail; the default assembler makes the
   sized declaration small data (`addiu $a0, $gp, ...`), an...
*/

/* US draft of func_003E4588 (rac3-uya-decomp func_003DF038, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */

/* PAL differences found against the retail bytes:
   - three colour/alpha constants differ in PAL (0.13f, 0.009f, 0.05f instead of the US
     0.1335f, 0.008f, 0.049333f);
   - D_001DA7E8 is addressed with lui/addiu in retail, so it is used through an unsized
     per-function alias (a sized declaration is small data and becomes a $gp access). */


/* localdecomp:start func_003E4588 */
__asm__(".extern D_001D9554, 1");
__asm__(".extern D_001D955D, 1");
__asm__(".extern D_001D955C, 1");
__asm__(".extern D_001D9760, 4");
typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038;
typedef struct { u8 pad[8]; VT_3DF038 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038;

extern u8 D_001D9554;
extern u8 D_001D955D;
extern u8 D_001D955C;
extern s32 D_001D9760;
extern s32 D_001DA7E8[2];
extern s32 D_001DA7E8_003E4588[];
extern S_3DF038 D_001DA938[];

extern void func_003E73B0_003E4588(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003B5060(s32);
extern s32 func_003E5090(s32);
extern s32 func_003E51F8(s32);
extern s32 func_003E5360(s32);
extern s32 func_00381FF0(s32);
extern s32 func_00392A18(void);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E7FF8(s32, s32, s32, s32, s32);
extern s32 func_003E8100(s32, s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E7590(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E7C90_003E4588(s32, void *);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_003E6FF0_003E4588(s32, s32);
extern void func_003E3E40(void);
extern S_3DF038 *func_003E6C08_003E4588(S_3DF038 *);
extern s32 func_003E6DE8_003E4588(S_3DF038 *);
extern W_3DF038 *func_003E6378(s32, s32);

void func_003E4588(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    W_3DF038 *t;
    W_3DF038 *v;

    D_001D9554 = 1;
    func_003E73B0_003E4588(1);
    func_0038CB78(D_001DA7E8_003E4588, 0, 8);
    func_003B5060(0x90000);
    func_003E5090(0x90001);
    func_003E5090(0x90002);
    func_003E51F8(0x90003);
    func_003E51F8(0x90004);
    func_003E51F8(0x90005);
    func_003E5360(0x90006);
    func_003E51F8(0x90007);
    func_003E8FE8(0x9000C, func_00381FF0(0x182D), 0x8066CCFF, 0.4285f, 0.1315f, 0.6f, 0.6f);
    func_003E7AC8(0x9000C, 1);
    func_003E9138(0x90008, 0x706EC8FF, 0, 0.598917f, 0.074f, 0.043083f, 0.050416f);
    func_003E7928(0x90008, 1, 3);
    func_003E7FF8(0x90008, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E8100(0x90002, func_00392A18(), 0x8C);
    func_003E8100(0x90001, func_00392A18(), 0x8D);
    func_003E73B8(0x90003, 0.487997f, 0.074f);
    func_003E73B8(0x90004, 0.440497f, 0.074f);
    func_003E73B8(0x90005, 0.39347f, 0.074f);
    func_003E73B8(0x90006, 0.627999f, 0.069f);
    func_003E7590(0x90006, 0.003f, 0.003f);
    func_003E7F20(0x90006, 1);
    func_003E73B8(0x90007, 0.464136f, 0.13f);
    func_003E81F0(0x90003, 0.035f, 0.035f);
    func_003E81F0(0x90004, 0.035f, 0.035f);
    func_003E81F0(0x90005, 0.035f, 0.035f);
    func_003E81F0(0x90006, 1.0f, 1.0f);
    func_003E81F0(0x90007, 0.0f, 0.009f);
    func_003E7D70(0x90001, 0x331465B7);
    func_003E7D70(0x90002, 0x332299DE);
    func_003E7D70(0x90003, 0x8066CCFF);
    func_003E7D70(0x90004, 0x8066CCFF);
    func_003E7D70(0x90005, 0x8066CCFF);
    func_003E7D70(0x90006, 0x8066CCFF);
    func_003E7D70(0x90007, 0x706EC8FF);
    func_003E7C90_003E4588(0x90006, D_001DA7E8_003E4588);
    func_003E7928(0x90006, 1, 1);
    func_003E7928(0x90007, 1, 3);
    func_003E7838(0x90006, 0x40, 1);
    func_003E7838(0x90003, 0x40, 1);
    func_003E7838(0x90004, 0x40, 1);
    func_003E7838(0x90005, 0x40, 1);
    func_003E7928(0x90003, 1, 3);
    func_003E7928(0x90004, 1, 3);
    func_003E7928(0x90005, 1, 3);

    func_003E7E48(0x90003, 0xED1C);
    p = D_001DA938;
    if (p->x4) q = p; else q = func_003E6C08_003E4588(p);
    t = func_003E6378(func_003E6DE8_003E4588(q), 0x90003);
    v = (t != 0 && t->vt->isA(t, D_001D9760) != 0) ? t : 0;
    v->x4A = 0;

    func_003E7E48(0x90004, 0xED1D);
    p = D_001DA938;
    if (p->x4) q = p; else q = func_003E6C08_003E4588(p);
    t = func_003E6378(func_003E6DE8_003E4588(q), 0x90004);
    v = (t != 0 && t->vt->isA(t, D_001D9760) != 0) ? t : 0;
    v->x4A = 0;

    func_003E7E48(0x90005, 0xED1E);
    p = D_001DA938;
    if (p->x4) q = p; else q = func_003E6C08_003E4588(p);
    t = func_003E6378(func_003E6DE8_003E4588(q), 0x90005);
    v = (t != 0 && t->vt->isA(t, D_001D9760) != 0) ? t : 0;
    v->x4A = 0;

    func_003E9138(0x9000A, 0x59000000, 0, 0.61558104f, 0.0739995f, 0.230333f, 0.05f);
    func_003E7928(0x9000A, 2, 3);
    func_003E9138(0x9000B, 0x59000000, 0, 0.385248f, 0.0739995f, 0.230333f, 0.05f);
    func_003E7928(0x9000B, 1, 3);
    func_003E7FF8(0x9000B, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E8630(0x90000, 0x90001);
    func_003E8630(0x90000, 0x90002);
    func_003E8630(0x90000, 0x9000A);
    func_003E8630(0x90000, 0x9000B);
    func_003E8630(0x90000, 0x90006);
    func_003E8630(0x90000, 0x90007);
    func_003E8630(0x90000, 0x90008);
    func_003E8630(0x90000, 0x90003);
    func_003E8630(0x90000, 0x90004);
    func_003E8630(0x90000, 0x90005);
    func_003E8630(0x90000, 0x9000C);
    func_003E8348(7, 0x90000);
    func_003E6FF0_003E4588(arg0, 1);
    func_003E3E40();
    func_003E73B0_003E4588(0);
    D_001D955D = 0;
    D_001D955C = 1;
}
/* localdecomp:end func_003E4588 */
