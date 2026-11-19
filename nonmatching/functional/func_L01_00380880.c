/* functional: high. Draft verified block by block against asm (scroll/wrap constants, packet offsets, culling dot test, both UV quads, row 11 colour mask). VU0 inline asm only for lqc2/vsub/sqc2. */
#include "common.h"
/* localdecomp:start func_L01_00380880 */
#include "structs/weapon.h"
typedef int Q_00380880 __attribute__((mode(TI)));
typedef struct {
    Q_00380880 points[4];
    u32 color[4];
    f32 uv[4][2];
    long zero, texture, flags, primitive;
} Packet_00380880;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern f32 D_001DDC58_sda, D_001DDC54_sda;
extern s32 D_001DDC3C_sda, D_001DDC40_sda;
extern f32 D_001DDC44_sda, D_001DDC48_sda, D_001DDC4C_sda;
extern u32 D_001DDC5C_sda, D_001DDC60_sda;
extern s32 D_001DDC64_sda;
extern f32 D_001DDBEC_sda, D_001DDBE8_sda;
extern f32 D_001DDBF8_sda, D_001DDBF0_sda, D_001DDBF4_sda;
extern f32 D_001DDBE4_sda, D_001DDBE0_sda;
extern Q_00380880 D_L01_0028F660[], D_L01_0028F720[];
extern Q_00380880 D_L01_0028F6A0[][20], D_L01_0028F7E0[][20];
extern Q_00380880 D_L01_001E29C0[];
void func_L01_00380880(void *arg) {
    extern void func_L01_00380CE0(void *, s32, s32, s32, u32, f32, f32, f32);
    extern void func_L01_003812B0(void *);
    extern void func_L01_00381500(void *);
    extern long func_00389598(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_00380880 packet;
    Q_00380880 normal_a, normal_b, normal, camera;
    u32 c1, c2;
    f32 v, u1, u2;
    s32 row, col, next, following;
    D_001DDC54_sda -= D_001DDC58_sda * 1.2f;
    if (D_001DDC54_sda <= -8.0f) D_001DDC54_sda += 8.0f;
    c1 = 0x00FF3F10;
    c2 = 0x007F1010;
    if (D_L01_002C5600[D_001425C0[0x8F]].level >= 4) {
        c1 = 0x00103FFF;
        c2 = 0x004080FF;
    }
    func_L01_00380CE0(D_L01_0028F660, D_001DDC3C_sda, D_001DDC40_sda, 12, c1, D_001DDC44_sda, D_001DDC48_sda, D_001DDC4C_sda);
    func_L01_00380CE0(D_L01_0028F720, D_001DDC3C_sda, D_001DDC40_sda, 12, c2, D_001DDC44_sda, D_001DDC48_sda, D_001DDC4C_sda);
    func_L01_003812B0(arg);
    func_L01_00381500(arg);
    c1 = D_L01_002C5600[D_001425C0[0x8F]].level < 4 ? D_001DDC5C_sda : D_001DDC60_sda;
    packet.texture = func_00389598(D_001DDC64_sda);
    packet.flags = 0x0000FF9000000260L;
    packet.primitive = 0x0000008000000048L;
    packet.zero = 0;
    packet.color[0] = c1;
    packet.color[3] = c1;
    packet.color[2] = c1;
    packet.color[1] = c1;
    v = D_001DDBE8_sda;
    D_001DDBE8_sda -= D_001DDBEC_sda * 1.2f;
    if (D_001DDBE8_sda <= -8.0f) D_001DDBE8_sda += 8.0f;
    D_001DDBF0_sda -= D_001DDBF8_sda * 1.2f;
    if (D_001DDBF0_sda <= -7.0f) D_001DDBF0_sda += 7.0f;
    D_001DDBF4_sda += D_001DDBF8_sda * 1.2f;
    if (D_001DDBF4_sda >= 5.0f) D_001DDBF4_sda -= 5.0f;
    for (row = 2; row < 12; row = following) {
        u1 = D_001DDBF0_sda;
        u2 = D_001DDBF4_sda;
        following = row + 1;
        for (col = 0; col < 20; col = next) {
            next = col + 1;
            packet.points[0] = D_L01_0028F7E0[row][col];
            packet.points[1] = D_L01_0028F7E0[row][next % 20];
            packet.points[2] = D_L01_0028F6A0[row][col];
            packet.points[3] = D_L01_0028F6A0[row][next % 20];
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(normal_a) : "m"(packet.points[0]), "m"(packet.points[1]) : "vf1", "vf2");
            __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(normal_b) : "m"(packet.points[2]), "m"(packet.points[1]) : "vf1", "vf2");
            func_0038CE90(&normal, &normal_b, &normal_a);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(camera) : "m"(packet.points[1]), "m"(D_L01_001E29C0[0]) : "vf1", "vf2");
            if (func_0038CE68(&normal, &camera) >= 0.0f) {
                u2 += D_001DDBE4_sda;
                u1 += D_001DDBE4_sda;
            } else {
                if (row == 11) {
                    packet.color[0] = D_001DDC5C_sda & 0xFFFFFF;
                    packet.color[1] = packet.color[0];
                }
                packet.uv[0][0] = v;
                packet.uv[0][1] = u1;
                packet.uv[1][0] = v;
                packet.uv[1][1] = u1 + D_001DDBE4_sda;
                packet.uv[2][0] = v - D_001DDBE0_sda;
                packet.uv[2][1] = u1;
                packet.uv[3][0] = v - D_001DDBE0_sda;
                packet.uv[3][1] = u1 + D_001DDBE4_sda;
                u1 += D_001DDBE4_sda;
                func_003D2DA0(&packet, 0, 0);
                packet.uv[0][0] = v;
                packet.uv[0][1] = u2;
                packet.uv[1][0] = v;
                packet.uv[1][1] = u2 + D_001DDBE4_sda;
                packet.uv[2][0] = v - D_001DDBE0_sda;
                packet.uv[2][1] = u2;
                packet.uv[3][0] = v - D_001DDBE0_sda;
                packet.uv[3][1] = u2 + D_001DDBE4_sda;
                u2 += D_001DDBE4_sda;
                func_003D2DA0(&packet, 0, 0);
            }
        }
        v += D_001DDBE0_sda;
    }
}
/* localdecomp:end func_L01_00380880 */
