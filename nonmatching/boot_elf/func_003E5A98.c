/* PAL near miss (Codex wave 7): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Compile blocked before byte diff: auto-added cross-file func_0038D348 declarations conflict (s32,s32,f32 versus void*,void*,f32); owner has no signature. Requires declaration context correction; log build/codex/w371/5A98-03.log
 */
#include "common.h"
/* localdecomp:start func_003E5A98 */
#include "vu0.h"
typedef unsigned int Q_003E5A98 __attribute__((mode(TI)));
typedef struct { f32 v[3]; u8 tag, pad[3]; f32 r[4]; } E_003E5A98;
typedef struct { u8 p[0x38]; s32 index; u8 p3C[0x28]; E_003E5A98 *entries; } C_003E5A98;
extern C_003E5A98 D_225700;
extern f32 D_225900[];
extern f32 D_222480[];
extern f32 D_2224A0[];
extern u8 D_001D5471;
extern f32 D_001D5BC8;
extern f32 D_001D5BCC;
s32 func_003E5A98(void) {
    extern void func_003877A0(void);
    extern void func_0012FF40(f32 *);
    extern void func_00130088(f32 *, f32 *, f32);
    extern void func_00130130(f32 *, f32 *, f32);
    extern void func_0012FFE0(f32 *, f32 *, f32);
    extern void func_0038D348(f32 *, f32 *, f32);
    extern void func_00384640(s32, f32 *, s32);
    extern void func_003850A8(s32);
    f32 m[16] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    E_003E5A98 *e = &D_225700.entries[D_225700.index];
    f32 *r = e->r;
    s32 tag = e->tag;
    D_225900[0xB0/4] = r[3];
    if (D_001D5471) D_225900[0xB0/4] *= D_001D5BC8;
    func_003877A0();
    *(Q_003E5A98 *)D_222480 = *(Q_003E5A98 *)e;
    func_0012FF40(m);
    func_00130088(m, m, e->r[0]);
    func_00130130(m, m, r[1]);
    func_0012FFE0(m, m, r[2]);
    D_222480[0x380/4] = -m[8];
    D_222480[0x390/4] = -m[0];
    D_222480[0x3A0/4] = m[4];
    D_222480[0x384/4] = -m[9];
    D_222480[0x394/4] = -m[1];
    D_222480[0x3A4/4] = m[5];
    D_222480[0x388/4] = -m[10];
    D_222480[0x398/4] = -m[2];
    D_222480[0x3A8/4] = m[6];
    if (D_001D5471 && D_001D5BCC != 0.0f) {
        *(Q_003E5A98 *)v = *(Q_003E5A98 *)&D_222480[0x380/4];
        func_0038D348(v, v, D_001D5BCC);
        vec_sub_ab(D_222480, D_222480, v);
    }
    func_00384640(0, D_2224A0, 0);
    func_00384640(0, D_2224A0 + 4, 1);
    func_00384640(0, D_2224A0 + 8, 2);
    func_003850A8(0);
    return tag;
}
/* localdecomp:end func_003E5A98 */
