/* NTSC-U draft (2026-11-14, Codex worker): C of func_L09_003E8270, the NTSC-U twin of func_L09_003E9FD0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/09_tyhrranosis/L09_003E9FD0.c's current line.
 * Worker's note: 439 diff; inline-literal assembler mismatch for 0x3B449BA6/0x3BB60B61/0x3D4CCCCD; global and VU scheduling also differ; native switch decoded in .switch.txt cases 1..8; no flags_alt; forbidden flags not tried; best log func_L09_003E8270.check02.log 439 diff; verified inherited best; allowed GNU asse
 */
#include "common.h"

/* localdecomp:start func_L09_003E8270 */
typedef int Q_003E8270 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003E8270;
extern u8 D_001A4BE0[];
extern s32 D_L09_002D1E70[], D_L09_001F2F40[];
extern u8 *D_001D52FC[], *D_L09_001E011C[];
extern f32 D_L09_001DF368[], D_L09_001DF348[], D_L09_001DFA50[];
extern f32 D_001DF350_sda, D_001DF360_sda, D_001DF330_sda, D_001DF340_sda, D_001DFA50_sda;
extern void func_L09_003E8AB0(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_00442050(void *, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0050DA68(void *, s32, f32);
extern s32 func_L01_0050DAC0(void);
extern void func_L01_003E6D50(s32, s32, f32, f32);
extern void func_L01_0050DB10(void);
extern void func_L09_00512408(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_003883C8(s16 *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_004282C0(s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003BF838(void *, void *, void *, void *);

void func_L09_003E8270(u8 *o)
{
    V_003E8270 delta;
    u8 *v;
    v = *(u8 **)(o + 0x68);
    func_L09_003E8AB0(o);
    switch (o[0x20]) {
    case 1:
        if (func_L01_00452EC8(o)) {
            func_L01_004A6D70(0, o);
            func_L01_00442050(o, 0);
        }
        if (o[0xBC] == 0 && D_001A4BE0[0x25E4] == 0 && *(s16 *)(D_001A4BE0 + 0x288C) == 0 &&
                *(u8 **)(D_001A4BE0 + 0x35C) == o && *(s32 *)(D_001A4BE0 + 0x360) >= 2) {
                func_L01_0044F2E8(0, 9, 0x11EA, 1, 0, 0, 0);
                if (D_L09_002D1E70[0] == 9 && (*(s32 *)(D_001D52FC[0] + 0x1A4) & 0x10)) {
                    func_L01_00442050(D_L09_001E011C[0] + (*(s32 *)(v + 0x78) << 8), 1);
                    func_L01_0050DA68(o + 0x10, 0, D_L09_001DF368[0]);
                    func_L01_00442050(o, 1);
                }
        } else if (o[0xBC] == 1) {
            if (func_L01_0050DAC0() == 2) {
                func_L01_003E6D50(0, 0, 2.5f, 0.003000000026077032f);
                func_L01_0050DB10();
                func_L09_00512408(0x74, 1);
                func_L01_00441FB8(o, 2, -1);
            } else if (o[0xBC] == 1 && func_L01_0050DAC0()) {
                func_L01_003E6D50(0, 0, 2.5f, 0.003000000026077032f);
            }
        }
        if (D_L09_001F2F40[0] == 1)
            func_L01_00441FB8(o, 2, -1);
        break;
    case 2:
        if (func_L01_00452EC8(o)) {
            *(s16 *)(v + 0x74) = 180;
            *(f32 *)(v + 0x70) = 0.0055555556900799274f;
            func_0039FE80(0, 4, o);
        }
        if (func_003883C8((s16 *)(v + 0x74))) {
            if (D_L09_001F2F40[0] != 1) {
                func_L01_004F12C0(&D_001DF350_sda, &D_001DF360_sda, 0x74, 1);
                D_001DFA50_sda = 1.5f;
                func_L01_004282C0(1, 0);
            }
            func_L01_00441FB8(o, 3, -1);
        } else {
            *(f32 *)(o + 0x18) = func_003BE6A8(*(f32 *)(v + 0x7C) + 10.0f, *(f32 *)(v + 0x7C), (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            func_L01_003E6D50(0, 0, 2.5f, 0.003000000026077032f);
            if (*(s16 *)(v + 0x74) < 60) {
                D_001DFA50_sda += 0.05f;
                if (1.0f <= D_001DFA50_sda)
                    D_001DFA50_sda = 1.0f;
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(o)) {
            func_L01_004A6D70(0, o);
            func_L01_00442050(o, 0);
        }
        if ((*(u8 **)(D_001A4BE0 + 0x35C) == o && *(s32 *)(D_001A4BE0 + 0x360) >= 2) || D_L09_001F2F40[0] == 2)
            func_L01_00441FB8(o, 4, -1);
        break;
    case 4:
        if (func_L01_00452EC8(o)) {
            *(s16 *)(v + 0x74) = 180;
            *(f32 *)(v + 0x70) = 0.0055555556900799274f;
            func_0039FE80(0, 4, o);
        }
        if (func_003883C8((s16 *)(v + 0x74))) {
            if (o[0xBC] == 1)
                func_L09_00512408(0, 1);
            func_L01_00441FB8(o, 1, -1);
        } else {
            *(f32 *)(o + 0x18) = func_003BE6A8(*(f32 *)(v + 0x7C), *(f32 *)(v + 0x7C) + 10.0f, (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            if (*(s16 *)(v + 0x74) < 160) {
                D_001DFA50_sda -= 0.05f;
                if (D_001DFA50_sda <= 0.0f)
                    D_001DFA50_sda = 0.0f;
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(o)) {
            func_L01_004A6D70(0, o);
            func_L01_00442050(o, 0);
        }
        if ((*(u8 **)(D_001A4BE0 + 0x35C) == o && *(s32 *)(D_001A4BE0 + 0x360) >= 2) || D_L09_001F2F40[0] == 1)
            func_L01_00441FB8(o, 6, -1);
        break;
    case 6:
        if (func_L01_00452EC8(o)) {
            *(s16 *)(v + 0x74) = 180;
            *(f32 *)(v + 0x70) = 0.0055555556900799274f;
            func_0039FE80(0, 4, o);
        }
        if (func_003883C8((s16 *)(v + 0x74))) {
            if (o[0xBC] == 1)
                func_L09_00512408(0, 1);
            func_L01_00441FB8(o, 7, -1);
        } else {
            *(f32 *)(o + 0x18) = func_003BE6A8(*(f32 *)(v + 0x7C), *(f32 *)(v + 0x7C) - 10.0f, (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            if (*(s16 *)(v + 0x74) < 160) {
                D_001DFA50_sda -= 0.05f;
                if (D_001DFA50_sda <= 0.0f)
                    D_001DFA50_sda = 0.0f;
            }
        }
        break;
    case 7:
        if (func_L01_00452EC8(o)) {
            func_L01_004A6D70(0, o);
            func_L01_00442050(o, 0);
        }
        if (o[0xBC] == 0 && D_001A4BE0[0x25E4] == 0 && *(s16 *)(D_001A4BE0 + 0x288C) == 0 &&
                *(u8 **)(D_001A4BE0 + 0x35C) == o && *(s32 *)(D_001A4BE0 + 0x360) >= 2) {
                func_L01_0044F2E8(0, 9, 0x11EB, 1, 0, 0, 0);
                if (D_L09_002D1E70[0] == 9 && (*(s32 *)(D_001D52FC[0] + 0x1A4) & 0x10)) {
                    func_L01_00442050(D_L09_001E011C[0] + (*(s32 *)(v + 0x78) << 8), 1);
                    func_L01_0050DA68(o + 0x10, 0, D_L09_001DF348[0]);
                    func_L01_00442050(o, 1);
                }
        } else if (o[0xBC] == 1) {
            if (func_L01_0050DAC0() == 2) {
                func_L01_003E6D50(0, 0, 2.5f, 0.003000000026077032f);
                func_L01_0050DB10();
                func_L09_00512408(0x74, 1);
                func_L01_00441FB8(o, 8, -1);
            } else if (o[0xBC] == 1 && func_L01_0050DAC0()) {
                func_L01_003E6D50(0, 0, 2.5f, 0.003000000026077032f);
            }
        }
        if (D_L09_001F2F40[0] == 2)
            func_L01_00441FB8(o, 8, -1);
        break;
    case 8:
        if (func_L01_00452EC8(o)) {
            *(s16 *)(v + 0x74) = 180;
            *(f32 *)(v + 0x70) = 0.0055555556900799274f;
            func_0039FE80(0, 4, o);
        }
        if (func_003883C8((s16 *)(v + 0x74))) {
            if (D_L09_001F2F40[0] != 2 && D_L09_001F2F40[0] != 0) {
                func_L01_004F12C0(&D_001DF330_sda, &D_001DF340_sda, 0x74, 1);
                D_001DFA50_sda = 1.5f;
                func_L01_004282C0(2, 0);
            }
            func_L01_00441FB8(o, 5, -1);
        } else {
            *(f32 *)(o + 0x18) = func_003BE6A8(*(f32 *)(v + 0x7C) - 10.0f, *(f32 *)(v + 0x7C), (f32)*(s16 *)(v + 0x74) * *(f32 *)(v + 0x70));
            func_L01_003E6D50(0, 0, 2.5f, 0.003000000026077032f);
            if (*(s16 *)(v + 0x74) < 60) {
                D_001DFA50_sda += 0.05f;
                if (1.0f <= D_001DFA50_sda)
                    D_001DFA50_sda = 1.0f;
            }
        }
        break;
    }
    __asm__(
        "lqc2 $vf2, %2
	"
        "lqc2 $vf1, %1
	"
        "vsub.xyz $vf1, $vf1, $vf2
	"
        "sqc2 $vf1, %0"
        : "=m"(delta)
        : "m"(*(V_003E8270 *)(o + 0x10)), "m"(*(V_003E8270 *)(v + 0x80))
        : "vf1", "vf2");
    func_003BF838(v + 0x30, &delta, o + 0xF0, o + 0xF0);
    *(V_003E8270 *)(v + 0x80) = *(V_003E8270 *)(o + 0x10);
}
/* localdecomp:end func_L09_003E8270 */
