/* PAL near miss (Codex wave 8): near miss: 86 words differ with the file's flags.
 * Worker's note: Best 79 diff; FPR allocation and branch scheduling remain; trial --divs 2 (not proven metadata); build/codex/w423/4F3F40-10.log
 */
#include "common.h"
/* localdecomp:start func_L01_004F3F40 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x1A8]; f32 turn;
    u8 pad1AC[0x12F4-0x1AC]; u8 *clank;
    u8 pad12F8[0x25C4-0x12F8]; s32 state;
} H_004F3F40;
typedef struct {
    u8 pad0[0xCC8]; f32 lean; 
    u8 padCCC[0xCF8-0xCCC]; f32 speed;
    u8 padCFC[8]; f32 gain; f32 damping; f32 reset;
} S_004F3F40;
extern St_004ECCD8 D_001A4BE0;
extern u8 D_001D5470 __attribute__((section(".data")));
extern f32 D_001DBD3C_sda;
__asm__(".extern D_001DBD3C_sda, 4");
extern Springs_4F2A08 D_L01_002F4540;
void func_L01_004F3F40(void) {
    H_004F3F40 *h = (H_004F3F40 *)&D_001A4BE0;
    f32 scale;
    f32 turn;
    
    f32 gain;
    S_004F3F40 *s;
    if (h->clank == 0) return;
    if (D_001D5470) {
        ((S_004F3F40 *)&D_L01_002F4540)->reset = D_001DBD3C_sda;
    }
    scale = 1024.0f / *(f32 *)(h->clank + 0x2C);
    if (h->state == 2) {
        turn = h->turn;
        s = (S_004F3F40 *)&D_L01_002F4540;
        s->gain = 0.02f;
        s->damping = 0.35f;
        if (turn > 1.4f) turn = 1.4f;
        else if (turn < -1.4f) turn = -1.4f;
        gain = -turn;
        gain *= 1.2f;
        if (gain > 1.30899692f) gain = 1.30899692f;
        else if (gain < -1.30899692f) gain = -1.30899692f;
        ((S_004F3F40 *)&D_L01_002F4540)->lean = gain;
        gain = fabs_asm(turn) * 0.1f + 0.1f;
        if (gain > 0.07f) gain = 0.07f;
        ((S_004F3F40 *)&D_L01_002F4540)->speed = gain * scale;
    }
}
/* localdecomp:end func_L01_004F3F40 */
