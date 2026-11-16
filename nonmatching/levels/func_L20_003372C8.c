/* PAL near miss (Codex wave 7): near miss: 242 words differ with the file's flags.
 * Worker's note: 242 diff, w364/L20-final.log. Full 0x2E0 frame reproduced; packet header setup, saved-register allocation, loop induction/speculative UV calculations and signed index range checks differ. Complete PAL reconstruction with existing VU0 helpers; fixed flags.
 */
#include "common.h"
/* localdecomp:start func_L20_003372C8 */
typedef struct Packet_003372C8 {
    vu0_v4 vertex[4];
    s32 color[4];
    f32 uv[4][2];
    unsigned long reserved, texture, test, primitive;
} Packet_003372C8;
typedef struct Matrix_003372C8 { vu0_v4 row[4]; } Matrix_003372C8;
extern s32 D_L20_001DBCA0;
extern vu0_v4 D_L20_001E2E00;
extern s32 D_L20_001DCAD0, D_L20_001DCAD4, D_L20_001DCAD8;
extern s32 D_L20_001DCADC, D_L20_001DCAE0;
extern f32 D_L20_001DCAF0[] __attribute__((section(".sdata")));
extern f32 D_L20_001DCAF4[];
__asm__(".extern D_L20_001DCAD0, 4");
__asm__(".extern D_L20_001DCAD4, 4");
__asm__(".extern D_L20_001DCAD8, 4");
__asm__(".extern D_L20_001DCADC, 4");
__asm__(".extern D_L20_001DCAE0, 4");
__asm__(".extern D_L20_001DCAF0, 4");
void func_L20_003372C8(void *self)
{
    extern void func_0038D328(void *, void *);
    extern void func_0038D5B0(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern unsigned long func_00389598(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003D2DA0(void *, void *, s32);
    Packet_003372C8 packet[3];
    Matrix_003372C8 matrix, inverse;
    vu0_v4 eye, previous, current, along, across;
    V_00337140 *v = *(V_00337140 **)((u8 *)self + 0x68);
    s32 i, j, k, n;
    unsigned long texture, primitive;
    D_L20_001DBCA0 |= 1;
    func_0038D328(&matrix, (u8 *)v + 0x650);
    func_0038D5B0(&inverse, &matrix);
    matrix.row[3] = *(vu0_v4 *)((u8 *)self + 0x10);
    vec_sub_ba(&eye, &D_L20_001E2E00, (u8 *)self + 0x10);
    func_0038D000(&eye, &eye, &inverse);
    texture = func_00389598(D_L20_001DCAD0);
    packet[0].test = packet[1].test = packet[2].test = 0xFF9000000260UL;
    primitive = (unsigned long)D_L20_001DCAD4 |
        ((unsigned long)D_L20_001DCAD8 << 2) |
        ((unsigned long)D_L20_001DCADC << 4) |
        ((unsigned long)D_L20_001DCAE0 << 6) | (0x8000UL << 24);
    packet[0].reserved = packet[1].reserved = packet[2].reserved = 0;
    packet[0].texture = packet[1].texture = packet[2].texture = texture;
    packet[0].primitive = packet[1].primitive = packet[2].primitive = primitive;
    { s32 c;
    for (c = 3; c >= 0; c--) {
        packet[0].uv[3 - c][1] = packet[1].uv[3 - c][1] =
            packet[2].uv[3 - c][1] = D_L20_001DCAF4[(3 - c) * 2];
        packet[0].color[3 - c] = packet[1].color[3 - c] =
            packet[2].color[3 - c] = v->color;
    }
    }
    qzero(&current);
    for (i = 0; i < 31; i++) {
        previous = current;
        if (i < 30) {
            vec_sub_ab(&across, (u8 *)v + 0x20 + i * 16, (u8 *)v + 0x40 + i * 16);
            vec_sub_ab(&along, (u8 *)v + 0x30 + i * 16, &eye);
            func_0038CE90(&current, &along, &across);
            func_0038CF68(&current, &current, 0.1f);
        } else {
            qzero(&current);
        }
        for (j = 0; j < 4; j++) {
            if (j < 2) {
                packet[0].vertex[j] = *(vu0_v4 *)((u8 *)v + 0x20 + i * 16);
                if (j & 1) vec_add_ab(&packet[0].vertex[j], &packet[0].vertex[j], &previous);
                else vec_sub_ab(&packet[0].vertex[j], &packet[0].vertex[j], &previous);
            } else {
                packet[0].vertex[j] = *(vu0_v4 *)((u8 *)v + 0x30 + i * 16);
                if (j & 1) vec_add_ab(&packet[0].vertex[j], &packet[0].vertex[j], &current);
                else vec_sub_ab(&packet[0].vertex[j], &packet[0].vertex[j], &current);
            }
            packet[0].uv[j][0] = D_L20_001DCAF0[j * 2] + (i % 4) * 0.25f;
        }
        func_003D2DA0(packet, &matrix, 0);
    }
    for (k = 0; k < 4; k++) {
        qzero(&current);
        n = v->idx[k];
        if (n < 31 && n >= 0) {
            for (i = 0; i < 3; i++) {
                previous = current;
                if (i < 2) {
                    vec_sub_ab(&across, &v->grid[i][k], &v->grid[i + 2][k]);
                    vec_sub_ab(&along, &v->grid[i + 1][k], &eye);
                    func_0038CE90(&current, &along, &across);
                    func_0038CF68(&current, &current, 0.1f);
                } else {
                    qzero(&current);
                }
                if (i == 0) previous = current;
                for (j = 0; j < 4; j++) {
                    if (j < 2) {
                        packet[0].vertex[j] = v->grid[i][k];
                        if (j & 1) vec_add_ab(&packet[0].vertex[j], &packet[0].vertex[j], &previous);
                        else vec_sub_ab(&packet[0].vertex[j], &packet[0].vertex[j], &previous);
                    } else {
                        packet[0].vertex[j] = v->grid[i + 1][k];
                        if (j & 1) vec_add_ab(&packet[0].vertex[j], &packet[0].vertex[j], &current);
                        else vec_sub_ab(&packet[0].vertex[j], &packet[0].vertex[j], &current);
                    }
                    packet[0].uv[j][0] = D_L20_001DCAF0[j * 2] + (i % 4) * 0.25f;
                }
                func_003D2DA0(packet, &matrix, 0);
            }
        }
    }
}
/* localdecomp:end func_L20_003372C8 */
