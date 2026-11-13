#include "common.h"

/* NTSC-U counterpart of func_L39_006D8E30 (src/levels/39_multiplayer_menu/L39_006D5208.c) */
/* localdecomp:start func_L39_006D62D8 */
typedef struct {
    u8 pad0[0x9D];
    u8 f9D;
} S3_006D8E30;
typedef struct {
    u8 pad0[0x50];
    S3_006D8E30 *f50;
} S_006D8E30;
extern u8 D_001A6134[];
s32 func_0019B860(void);
void func_0017DF60(void);
void func_L39_006DA7E0(void *);

s32 func_L39_006D62D8(S_006D8E30 *arg0) {
    D_001A6134[0] = 0;
    func_0019B860();
    if (arg0->f50->f9D) {
        func_L39_006DA7E0(arg0->f50);
    }
    func_0017DF60();
    return 1;
}
/* localdecomp:end func_L39_006D62D8 */
