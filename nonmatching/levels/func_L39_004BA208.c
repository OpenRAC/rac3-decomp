/* func_L39_004BA208: matches alone, but its two jump tables do not sit with the rest of the file's read-only data in retail (level_symbols: two places for the file's .rodata in level 39) (reverted from src/levels/39_multiplayer_menu/L39_004B9160.c, 2026-11-27). */
#include "common.h"
/* localdecomp:start func_L39_004BA208 */
extern void func_L39_004BB3E8(s32);
extern s32 D_L39_00443074;
extern s32 D_L39_00464794[];
extern s32 D_L39_00464798[];
extern s32 D_L39_0046479C[];
extern s32 D_L39_004647A0;
extern s32 D_L39_004647A8;
extern u8 D_L39_00443078[];
extern u8 D_L39_00443178[];
extern u8 D_L39_00443280[];

void func_L39_004BA208(void *ssl, s32 where, s32 ret) {
    u32 i;
    u8 *p;

    if (where & 0x4000) {
        if (where & 8) {
            switch (ret & 0xFF) {
            case 0x0:
                func_L39_004BB3E8(0x40);
                break;
            case 0xA:
                func_L39_004BB3E8(0x41);
                break;
            case 0x14:
                func_L39_004BB3E8(0x42);
                break;
            case 0x1E:
                func_L39_004BB3E8(0x43);
                break;
            case 0x28:
                func_L39_004BB3E8(0x44);
                break;
            case 0x29:
                func_L39_004BB3E8(0x45);
                D_L39_0046479C[0] = 1;
                break;
            case 0x2A:
                func_L39_004BB3E8(0x46);
                break;
            case 0x2B:
                func_L39_004BB3E8(0x47);
                break;
            case 0x2C:
                func_L39_004BB3E8(0x48);
                break;
            case 0x2D:
                func_L39_004BB3E8(0x49);
                break;
            case 0x2E:
                func_L39_004BB3E8(0x4A);
                break;
            case 0x2F:
                func_L39_004BB3E8(0x4B);
                break;
            case 0x15:
                func_L39_004BB3E8(0x80);
                break;
            case 0x16:
                func_L39_004BB3E8(0x81);
                break;
            case 0x30:
                func_L39_004BB3E8(0x82);
                break;
            case 0x31:
                func_L39_004BB3E8(0x83);
                break;
            case 0x32:
                func_L39_004BB3E8(0x84);
                break;
            case 0x33:
                func_L39_004BB3E8(0x85);
                break;
            case 0x3C:
                func_L39_004BB3E8(0x86);
                break;
            case 0x46:
                func_L39_004BB3E8(0x87);
                break;
            case 0x47:
                func_L39_004BB3E8(0x88);
                break;
            case 0x50:
                func_L39_004BB3E8(0x89);
                break;
            case 0x5A:
                func_L39_004BB3E8(0x8A);
                break;
            case 0x64:
                func_L39_004BB3E8(0x8B);
                break;
            case 0x1:
                func_L39_004BB3E8(0x60);
                break;
            case 0x2:
                func_L39_004BB3E8(0x61);
                D_L39_0046479C[0] = 1;
                break;
            case 0x4:
                func_L39_004BB3E8(0x62);
                break;
            case 0x6:
                func_L39_004BB3E8(0x63);
                break;
            }
        }
        if (where & 4) {
            switch (ret & 0xFF) {
            case 0x0:
                func_L39_004BB3E8(0x50);
                break;
            case 0xA:
                func_L39_004BB3E8(0x51);
                break;
            case 0x14:
                func_L39_004BB3E8(0x52);
                break;
            case 0x1E:
                func_L39_004BB3E8(0x53);
                break;
            case 0x28:
                func_L39_004BB3E8(0x54);
                break;
            case 0x29:
                func_L39_004BB3E8(0x55);
                break;
            case 0x2A:
                func_L39_004BB3E8(0x56);
                break;
            case 0x2B:
                func_L39_004BB3E8(0x57);
                break;
            case 0x2C:
                func_L39_004BB3E8(0x58);
                break;
            case 0x2D:
                func_L39_004BB3E8(0x59);
                break;
            case 0x2E:
                func_L39_004BB3E8(0x5A);
                break;
            case 0x2F:
                func_L39_004BB3E8(0x5B);
                break;
            case 0x15:
                func_L39_004BB3E8(0x90);
                break;
            case 0x16:
                func_L39_004BB3E8(0x91);
                break;
            case 0x30:
                func_L39_004BB3E8(0x92);
                break;
            case 0x31:
                func_L39_004BB3E8(0x93);
                break;
            case 0x32:
                func_L39_004BB3E8(0x94);
                break;
            case 0x33:
                func_L39_004BB3E8(0x95);
                break;
            case 0x3C:
                func_L39_004BB3E8(0x96);
                break;
            case 0x46:
                func_L39_004BB3E8(0x97);
                break;
            case 0x47:
                func_L39_004BB3E8(0x98);
                break;
            case 0x50:
                func_L39_004BB3E8(0x99);
                break;
            case 0x5A:
                func_L39_004BB3E8(0x9A);
                break;
            case 0x64:
                func_L39_004BB3E8(0x9B);
                break;
            case 0x1:
                func_L39_004BB3E8(0x70);
                break;
            case 0x2:
                func_L39_004BB3E8(0x71);
                break;
            case 0x4:
                func_L39_004BB3E8(0x72);
                break;
            case 0x6:
                func_L39_004BB3E8(0x73);
                break;
            }
        }
        if (D_L39_00443074 == 2) {
            if (D_L39_004647A0 > 0) {
                if (D_L39_004647A8 == 3) {
                    ((void (*)(void))func_L39_004BB368)();
                }
                p = D_L39_00443280;
                for (i = 0; i < 0x32; i++) {
                    p[i] = 0;
                }
                D_L39_004647A0 = 0;
            }
        } else if (D_L39_00464794[0] > 0 && (where & 4)) {
            if (D_L39_004647A8 == 3) {
                ((void (*)(void))func_L39_004BB368)();
            }
            p = D_L39_00443078;
            for (i = 0; i < 0x100; i++) {
                p[i] = 0;
            }
            D_L39_00464794[0] = 0;
        } else if (D_L39_00464798[0] > 0 && (where & 8)) {
            if (D_L39_004647A8 == 3) {
                ((void (*)(void))func_L39_004BB368)();
            }
            p = D_L39_00443178;
            for (i = 0; i < 0x100; i++) {
                p[i] = 0;
            }
            D_L39_00464798[0] = 0;
        }
    }
}
/* localdecomp:end func_L39_004BA208 */
