#include "common.h"

/* NTSC-U counterpart of func_L39_006C4148 (src/levels/39_multiplayer_menu/L39_006C4148.c) */
/* localdecomp:start func_L39_006C1630 */
typedef struct {
    s32 id;
    s32 age;
    char name[0x20];
} S_006C4148;

extern u8 *D_L39_002417C0;
extern S_006C4148 D_L39_001FD7B0[11];
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad[0x7C9];
    u8 b7D5[8];
} S_1A5CD0_006C4148;
extern S_1A5CD0_006C4148 D_001A5E50_006C1630;
extern char *func_001206F4(char *, char *);

void func_L39_006C1630(void *obj) {
    s32 i;
    s32 k;
    s32 j;

    if (D_L39_002417C0 == 0) {
        return;
    }
    for (j = 0; j < 11; j++) {
        D_L39_001FD7B0[j].age++;
    }
    for (i = 0; i < 8; i++) {
        s16 v;
        if (*(s16 *)(D_L39_002417C0 + (i << 1) + 0xE0) == -1) {
            D_001A5E50_006C1630.b7D5[i] = 2;
        } else {
            D_001A5E50_006C1630.b7D5[i] = 0;
        }
        v = *(s16 *)(D_L39_002417C0 + (i << 1) + 0xE0);
        if (v != -1 && v != D_001A5E50_006C1630.w8) {
            s32 *ids = (s32 *)(D_L39_002417C0 + 0x150);
            s32 found = 0;
            s32 best = 0;
            s32 bi = -1;
            for (k = 0; k < 11; k++) {
                if (D_L39_001FD7B0[k].id == *(s32 *)((u8 *)ids + (i << 2))) {
                    D_L39_001FD7B0[k].age = 1;
                    found = 1;
                }
                if (best < D_L39_001FD7B0[k].age) {
                    best = D_L39_001FD7B0[k].age;
                    bi = k;
                }
                if (D_L39_001FD7B0[k].id < 0) {
                    bi = k;
                    break;
                }
            }
            if (!found && bi >= 0) {
                D_L39_001FD7B0[bi].id = *(s32 *)(D_L39_002417C0 + (i << 2) + 0x150);
                D_L39_001FD7B0[bi].age = 1;
                func_001206F4(D_L39_001FD7B0[bi].name, (char *)(D_L39_002417C0 + i * 16));
            }
        }
    }
}
/* localdecomp:end func_L39_006C1630 */
