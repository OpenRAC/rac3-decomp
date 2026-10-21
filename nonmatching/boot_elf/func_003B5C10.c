/* US draft of func_003B5C10 (rac3-uya-decomp func_003B5A60, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B5C10 */
typedef struct {
    s32 f0; s32 f4; s32 f8; s32 fC; f32 f10; f32 f14; f32 f18; f32 f1C;
    u32 f20; s32 f24; f32 f28; u32 f2C;
} E_3B02A0;
extern void func_003E9808();
extern s32 func_003E9110(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E92A8(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E94F0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9470(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9710(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E7A38(s32, f32);
extern s32 func_003E7948(s32, f32, f32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E91F0(s32, s32, s32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
void func_003B5C10(E_3B02A0 *tbl) {
    s32 i;
    s32 h = 3;
    s32 v = 3;
    for (i = 0; tbl[i].f0 != 0; i++) {
        E_3B02A0 *e = &tbl[i];
        u32 f;
        switch (e->f8) {
        case 0:
            ((s32 (*)())func_003E9808)(e->f0);
            if (e->f2C & 1) {
                func_003E9110(e->f0, 1, 1);
                func_003E7770(e->f0, e->f10, e->f14);
                func_003E85A8(e->f0, e->f18, e->f1C);
            }
            break;
        case 1:
            func_003E92A8(e->f0, e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.0f);
            break;
        case 2:
            ((s32 (*)(s32, s32, f32, f32, f32, f32, s32))func_003E94F0)(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f24);
            break;
        case 3:
            func_003E9628(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f28, e->f28);
            break;
        case 4: {
            s32 id;
            if (e->f2C & 4) id = func_003823D0(e->f24);
            else id = e->f24;
            func_003E9470(e->f0, id, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.005f, 0.005f);
            break;
        }
        case 5: {
            s32 id;
            if (e->f2C & 4) id = func_003823D0(e->f24);
            else id = e->f24;
            func_003E9710(e->f0, id, e->fC, e->f10, e->f14, e->f18, e->f1C, 1.0f);
            func_003E7A38(e->f0, e->f28);
            func_003E7948(e->f0, e->f28 * 0.005f, e->f28 * 0.005f);
            func_003E7BF0(e->f0, 0x40, 1);
            if (e->f2C & 8) func_003E91F0(e->f0, 1, 1);
            break;
        }
        }
        f = e->f20;
        if (f != 0) {
            if (f & 1) h = 1;
            else if (f & 2) h = 2;
            if (f & 8) v = 1;
            else if (f & 0x10) v = 2;
            func_003E7CE0(e->f0, h, v);
        }
        if (e->f2C & 2) func_003E7BF0(e->f0, 1, 0);
        if (e->f4) func_003E89E8(e->f4, e->f0);
    }
}
/* localdecomp:end func_003B5C10 */
