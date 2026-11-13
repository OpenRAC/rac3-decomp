#include "common.h"

/* NTSC-U counterpart of func_L39_006CC018 (src/levels/39_multiplayer_menu/L39_006CC018.c) */
/* localdecomp:start func_L39_006C9528 */
extern s32 D_L39_002417C0;
extern s32 D_L39_002407C0;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

struct S_006CC018 {
    s32 w;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad[0x19];
};

typedef struct S_006CC018G {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x168 - 8];
    u8 f168;
    u8 pad169[0x644 - 0x169];
    s32 slot[8];
    u8 pad664[8];
} S_006CC018G;
extern S_006CC018G D_001A5E50;

void func_L39_006C9528(void *object)
{
    s32 i;
    struct S_006CC018 st;

    if (D_L39_002417C0 != 0) {
        if (D_001A5E50.f168 != 0) {
            for (i = 0; i < 7; i++) {
                if (D_001A5E50.slot[i] != -1) {
                    st.b6 = *(u8 *)(&D_001A5E50.slot[i] + 8);
                    st.w = 0;
                    st.b5 = 0;
                    st.b4 = 0;
                    func_0014AD08(0x50, D_001A5E50.f4, D_001A5E50.slot[i], D_L39_002407C0, 0x20, &st);
                    D_001A5E50.slot[i] = -1;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006C9528 */
