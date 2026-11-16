/* PAL near miss (Codex wave 6): near miss: 87 words differ with the file's flags.
 * Worker's note: 28 diff w273/func_L07_003B84C0.check04.log: missing andi v0,v0,255 before three byte stores shifts tail by one instruction; three conversions produced same bytes. Tested injected divs 2 2; not MATCH.
 */
#include "common.h"
/* localdecomp:start func_L07_003B84C0 */
typedef struct S_003B84C0 {
 u8 pad0[0x30]; f32 health; s16 hp; u8 pad36[0xE]; u8 c44,c45,c46; u8 pad47[0x149]; u8 *data; u8 pad194[0xF4]; s32 handle; u8 pad28C[0xA]; u8 c296; u8 pad297[2]; u8 c299; u8 pad29A; u8 c29B; s16 h29C,h29E,h2A0,h2A2;
} S_003B84C0;
typedef int Q_003B84C0 __attribute__((mode(TI)));
extern u8 D_001426E0[];
extern u8 D_00142660[];
void func_L07_003B84C0(u8 *arg0) {
    extern s32 func_L01_0041A4F0(void);
    extern f32 func_L07_00334A98(s32);
    extern f32 func_L01_004DFE88(s32);
    extern s32 func_L07_003A7378(void *, s32, void *, s32, f32);
    extern void func_L07_00334800(void *);
    extern void func_L07_003B8690(void *, s32);
    S_003B84C0 *s = *(S_003B84C0 **)(arg0 + 0x68);
    f32 scale;
    f32 v;
    f32 rate;
    f32 difficulty;
    Q_003B84C0 vec;
    if (D_001426E0[0x83] == 0) {
        D_001426E0[0x83] = D_00142660[8];
        D_001426E0[0xD7] = D_00142660[0x40];
    }
    if (func_L01_0041A4F0()) {
        s->hp = 1000;
        scale = 1000.0f / s->h2A0;
        s->health = 1000.0f;
    } else {
        scale = func_L07_00334A98(D_001426E0[0x83]);
        s->hp = (s32)(s->h2A0 * scale);
        s->health = s->hp;
    }
    v = scale * s->h2A2;
    if (v > 65535.0f) v = 65535.0f;
    *(s16 *)(arg0 + 0xB6) = (s32)v;
    rate = func_L01_004DFE88(D_001426E0[0xD7]);
    difficulty = (f32)D_001426E0[0x83];
    s->c296 = 0;
    s->c46 = s->c44 = (s->c45 = (u8)(s32)((difficulty / rate) * 0.125f));
    vec = 0;
    ((f32 *)&vec)[2] = 3.0f;
    s->handle = func_L07_003A7378(arg0, 0, &vec, s->c45, *(f32 *)(s->data + 0x18));
    s->c299 = 0;
    s->c29B = 0;
    s->h29C = 0;
    s->h29E = 0;
    func_L07_00334800(arg0);
    func_L07_003B8690(arg0, 2);
}
/* localdecomp:end func_L07_003B84C0 */
