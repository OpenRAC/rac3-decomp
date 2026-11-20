#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[32];
    s32 src;
    u8 pad36[96];
    s32 mode;
} S_47A458;
typedef struct {
    s32 pad[3];
    s32 a[4];
} S_47A608;
typedef struct { s32 x0; s32 x4; s32 next; s32 arr[4]; } Struct002E9FD8;
typedef struct {
    s32 state;
    u8 pad4[24];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 pad2C[68];
    u8 unk70;
} S_002E9FD8;
typedef struct {
    u8 pad0[112];
    u8 x70;
    u8 pad71[3];
    s32 x74;
} S_0047B230;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8[2];
} T_0047B230;

typedef struct {
    u8 pad0[0x1C0];
    s32 w1C0;
    s32 w1C4;
} S_0047E680;

typedef struct {
    u8 pad0[0x24];
    u32 key1;
    u32 key2;
} S_0047EDC0;
typedef struct {
    u32 key;
    s32 flags;
} Chunk_0047EDC0;

/* localdecomp:start func_L01_0047DBB0 */
typedef int Quad_0047DBB0 __attribute__((mode(TI)));
extern char D_L01_002E9F98_0047DBB0[];
extern int D_L01_001DF948;
extern int D_001D4BC4;
extern int D_001D4BB4;
__asm__(".extern D_001D4BB4, 4");
void func_L01_0047DBB0(int from_end)
{
    extern void func_003A92F0(int);
    extern int func_0012C908(int);
    extern void func_0012C9A0(void *, short, int, int, int, int, int, int);
    extern void func_0011F0A0(int);
    extern void func_0012CCC8(void *, char *);
    extern void func_0012A9F0(int, int);
    Quad_0047DBB0 image[6];
    int remaining;
    int dest_addr;
    char *src_ptr;
    char *state = D_L01_002E9F98_0047DBB0;

    *(int *)(state + 0x84) = from_end != 0 ? 2 : 1;
    func_003A92F0(1);
    func_0012C908(0);
    D_L01_001DF948++;
    remaining = D_001D4BC4 * 0x600;
    src_ptr = *(char **)(state + 0x20);
    dest_addr = D_001D4BB4;
    if (from_end != 0)
        dest_addr = 0x3FB000 - remaining;
    for (; remaining >= 0; remaining -= 0x4000) {
        func_0012C9A0(&image, dest_addr >> 8, 1, 0, 0, 0, 64, 64);
        dest_addr += 0x4000;
        func_0011F0A0(0);
        func_0012CCC8(&image, src_ptr);
        src_ptr += 0x4000;
        func_0012A9F0(0, 0);
    }
}
/* localdecomp:end func_L01_0047DBB0 */

/* localdecomp:start func_L01_0047DCB8 */


extern S_47A458 D_L01_002E9F98;
extern s32 D_L01_001DF948;
extern s32 D_001D4BC4;
extern s32 D_001D4BB4;
extern void func_003A92F0(s32);
extern void func_0012C908(s32);
extern void func_0012CB88(void *, s16, s32, s32, s32, s32, s32, s32);
extern void func_0011F0A0(s32);
extern void func_0012CE48(void *, s32);
extern void func_0012A9F0(s32, s32);

void func_L01_0047DCB8(void) {
    s128 buf[7];
    s32 size;
    s32 dst;
    s32 src;

    func_003A92F0(1);
    func_0012C908(0);
    D_L01_001DF948++;
    size = D_001D4BC4 * 1536;
    src = D_L01_002E9F98.src;
    dst = D_001D4BB4;
    if (D_L01_002E9F98.mode >= 2) {
        dst = 0x3FB000 - size;
    }
    for (; size >= 0; size -= 16384) {
        func_0012CB88(buf, dst >> 8, 1, 0, 0, 0, 64, 64);
        dst += 16384;
        func_0011F0A0(0);
        func_0012CE48(buf, src);
        src += 16384;
        func_0012A9F0(0, 0);
    }
    D_L01_002E9F98.mode = 0;
}
/* localdecomp:end func_L01_0047DCB8 */

LINKER_REMNANT("asm/levels", func_L01_0047DDC0);

/* localdecomp:start func_L01_0047DDC8 */
extern S_002E9FD8 D_L01_002E9F98_0047DDC8;
extern void func_L01_003F1F10_0047DDC8(s32);
extern void func_L01_00459EF0(void);
extern void func_0013C1A0(s32);
extern void func_L01_0045F328(s32);
extern void func_0013B620(void);
extern void *func_L01_0047EB88(void);
extern s32 func_003E8440(void *);
extern void func_003A5348(s32, s32, s32);
extern void func_003A2CD8(void *);
__asm__(".extern D_L01_001D8224_0047DDC8, 1");
extern u8 D_L01_001D8224_0047DDC8;
extern S_0047E680 *D_001D52FC;

void func_L01_0047DDC8(s32 a0) {
    func_L01_003F1F10_0047DDC8(a0);
    func_L01_00459EF0();
    func_0013C1A0(0x4D);
    func_L01_0045F328(0);
    func_0013B620();
    if (D_L01_002E9F98_0047DDC8.unk70 == 0) {
        D_L01_002E9F98_0047DDC8.state = a0;
    }
    func_003E8440(func_L01_0047EB88());
    if (D_L01_001D8224_0047DDC8 != 0) {
        D_L01_001D8224_0047DDC8 = 0;
        func_003A5348(0x12, 0, 0);
    }
    if (D_001D52FC != 0) {
        func_003A2CD8(D_001D52FC);
    }
}
/* localdecomp:end func_L01_0047DDC8 */

/* localdecomp:start func_L01_0047DE68 */
extern S_47A458 D_L01_002E9F98;
extern void func_0038CB78(s32, s32, s32);
void func_L01_0047DE68(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_0038CB78((*(S_47A608 *)&D_L01_002E9F98).a[i], 0, 2048);
    }
}
/* localdecomp:end func_L01_0047DE68 */

/* localdecomp:start func_L01_0047DEC0 */
extern S_47A458 D_L01_002E9F98;
extern void func_L01_0047DE68(void);
void func_L01_0047DEC0(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        (*(Struct002E9FD8 *)&D_L01_002E9F98).arr[i] = (*(Struct002E9FD8 *)&D_L01_002E9F98).next;
        (*(Struct002E9FD8 *)&D_L01_002E9F98).next += 2048;
    }
    func_L01_0047DE68();
}
/* localdecomp:end func_L01_0047DEC0 */

/* localdecomp:start func_L01_0047DF10 */
extern S_47A458 D_L01_002E9F98;
void func_L01_0047DF10(void) {
    s32 i;
    for (i = 3; i >= 0; i--) {
        (*(Struct002E9FD8 *)&D_L01_002E9F98).arr[i] = 0;
    }
}
/* localdecomp:end func_L01_0047DF10 */

INCLUDE_ASM("asm/levels", func_L01_0047DF40);

/* localdecomp:start func_L01_0047E330 */
extern void *func_L01_0047EBE0(void);
extern void *func_L01_00495030(void);
extern void *func_L01_00496378(void);
extern void *func_L01_0047FE28(void);
extern void *func_L01_00484028(void);
extern void *func_L01_00484AA0(void);
extern void *func_L01_0048FB98(void);
extern void *func_L01_0048A028(void);
extern void *func_L01_00496868(void);
extern void *func_L01_0049B4F8(void);
extern void *func_L01_004800D8(void);
extern void *func_L01_0049C630(void);
extern void *func_L01_0049B550(void);
extern void *func_L01_00492870(void);
extern void func_L01_00517748(void *);
extern void func_L01_00516090_0047E330(s32);
extern S_002E9FD8 D_L01_002E9F98_0047E330;

void func_L01_0047E330(s32 a0) {
    switch (D_L01_002E9F98_0047E330.state) {
    case 16:
        func_L01_00517748(func_L01_0047EBE0());
        break;
    case 14:
        func_L01_00517748(func_L01_00495030());
        break;
    case 15:
        func_L01_00517748(func_L01_00496378());
        break;
    case 1:
        func_L01_00517748(func_L01_0047FE28());
        break;
    case 5:
        func_L01_00517748(func_L01_00484028());
        break;
    case 6:
        func_L01_00517748(func_L01_00484AA0());
        break;
    case 2:
        func_L01_00517748(func_L01_0048FB98());
        break;
    case 4:
        func_L01_00517748(func_L01_0048A028());
        break;
    case 17:
        func_L01_00517748(func_L01_00496868());
        break;
    case 18:
        func_L01_00517748(func_L01_0047EBE0());
        break;
    case 19:
        func_L01_00517748(func_L01_0049B4F8());
        break;
    case 7:
        func_L01_00517748(func_L01_004800D8());
        break;
    case 20:
        func_L01_00517748(func_L01_0049C630());
        break;
    case 21:
        func_L01_00517748(func_L01_0049B550());
        break;
    case 22:
        func_L01_00517748(func_L01_00492870());
        break;
    default:
        func_L01_00517748(func_L01_0047EBE0());
        break;
    }
    func_L01_00516090_0047E330(a0);
}
/* localdecomp:end func_L01_0047E330 */

/* localdecomp:start func_L01_0047E490 */
extern u8 D_L01_002EA00A[];

void func_L01_0047E490(void) {
    D_L01_002EA00A[0] = 1;
}
/* localdecomp:end func_L01_0047E490 */

/* localdecomp:start func_L01_0047E4A0 */
extern u8 D_L01_002EA00A[];
u8 func_L01_0047E4A0(void) {
    return D_L01_002EA00A[0];
}
/* localdecomp:end func_L01_0047E4A0 */

/* localdecomp:start func_L01_0047E4B0 */
void func_L01_0047E4B0(void) {

}
/* localdecomp:end func_L01_0047E4B0 */

/* localdecomp:start func_L01_0047E4B8 */
void func_L01_0047E4B8(void) {

}
/* localdecomp:end func_L01_0047E4B8 */

/* localdecomp:start func_L01_0047E4C0 */
extern void *D_L01_002E9FB8[];
extern s32 D_L01_001D6694;
extern s32 D_001A1ED4[];
extern s32 D_001D4BC4;
extern void func_L01_004C6030(void *a0, s32 a1, s32 a2);
extern void func_0038AE20(s32 a0, s32 a1, s32 a2, s32 a3);
void func_L01_0047E4C0(void) {
    void *p = D_L01_002E9FB8[0];
    if (p != 0 && D_L01_001D6694 == 3) {
        func_L01_004C6030(p, D_001A1ED4[0], D_001D4BC4 << 11);
        func_0038AE20(0, 0, 0, 96);
    }
}
/* localdecomp:end func_L01_0047E4C0 */

/* localdecomp:start func_L01_0047E520 */
extern void func_003B98A0();
extern void func_L01_0047EDB8_0047E520();

 
void func_L01_0047E520(void) {
    func_L01_0047EDB8_0047E520();
    func_003B98A0();
}
/* localdecomp:end func_L01_0047E520 */

/* localdecomp:start func_L01_0047E548 */
extern void func_L01_0047E4B8_0047E548();
 
void func_L01_0047E548(void) {
    func_L01_0047E4B8_0047E548();
}
/* localdecomp:end func_L01_0047E548 */

/* localdecomp:start func_L01_0047E568 */
extern S_47A458 D_L01_002E9F98;

extern s32 D_L01_001D6690;
extern s32 D_L01_001D6694;
extern u8 D_L01_001D672E;
extern void func_L01_0047DBB0(s32);
extern void func_003A9050(void);
extern void func_L01_0047DF10(void);
extern void func_0013C1D0(s32);
extern s32 func_L01_0041A4C0(void);
extern void func_003A1D00(void);
extern void func_0013B620(void);
extern s32 func_003A4288(void);
extern void func_L01_004606A8(s32);
extern void func_L01_0041A008(s32);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_0047DAC8(void);

void func_L01_0047E568(void)
{
    if ((u32)(((S_002E9FD8 *)&D_L01_002E9F98)[0].state - 20) < 2) {
        func_L01_0047DBB0(1);
    }
    func_003A9050();
    ((S_002E9FD8 *)&D_L01_002E9F98)[0].unk24 = 0;
    ((S_002E9FD8 *)&D_L01_002E9F98)[0].unk28 = 0;
    func_L01_0047DF10();
    ((S_002E9FD8 *)&D_L01_002E9F98)[0].unk1C = 0;
    if (((S_002E9FD8 *)&D_L01_002E9F98)[0].unk70 == 0 || (u32)(((S_002E9FD8 *)&D_L01_002E9F98)[0].state - 20) >= 2) {
        ((S_002E9FD8 *)&D_L01_002E9F98)[0].unk20 = 0;
    }
    if (D_L01_001D6690 != 5 && D_L01_001D6694 != 5) {
        func_0013C1D0(77);
    }
    if (func_L01_0041A4C0() == 0 && D_L01_001D6690 != 5 && D_L01_001D6694 != 5) {
        func_003A1D00();
    }
    func_0013B620();
    func_003A4288();
    func_L01_004606A8(0);
    D_L01_001D672E = 0;
    func_L01_0041A008(0);
    if (D_L01_001D6690 == 0) {
        func_003A5348(20, 0, 0);
    }
    func_L01_0047DAC8();
}
/* localdecomp:end func_L01_0047E568 */

/* localdecomp:start func_L01_0047E680 */
__asm__(".extern D_L01_001E05E4, 4");
__asm__(".extern D_L01_001E05E0, 4");
__asm__(".extern D_L01_001E05EC, 4");
__asm__(".extern D_L01_001E05E8, 4");
__asm__(".extern D_L01_001D826C, 4");
__asm__(".extern D_L01_001D8264, 4");
__asm__(".extern D_L01_001D8268, 4");
extern S_0047E680 *D_001D52FC;
extern s32 D_L01_001E05E4;
extern s32 D_L01_001E05E0;
extern s32 D_L01_001E05EC;
extern s32 D_L01_001E05E8;
extern s32 D_L01_001D826C;
extern s32 D_L01_001D8264;
extern s32 D_L01_001D8268;

void func_L01_0047E680(void) {
    s32 v;
    s32 n;

    if (D_L01_001E05E4 == 0) {
        D_L01_001E05E4 = 1;
        D_L01_001E05E0 = D_L01_001D826C;
    }
    if (D_L01_001E05EC == 0) {
        D_L01_001E05EC = 1;
        D_L01_001E05E8 = D_001D52FC->w1C0 & D_L01_001D8264;
    }
    v = D_001D52FC->w1C0;
    if (v != 0 && v == D_L01_001E05E8) {
        n = D_L01_001E05E0 - 1;
        D_L01_001E05E0 = n;
        if (n == 0 || n == 0xFF) {
            D_L01_001E05E0 = D_L01_001D8268;
            D_001D52FC->w1C4 = v & D_L01_001D8264;
        }
    } else {
        D_L01_001E05E0 = D_L01_001D826C;
    }
    D_L01_001E05E8 = D_001D52FC->w1C0;
}
/* localdecomp:end func_L01_0047E680 */

/* localdecomp:start func_L01_0047E738 */
extern void func_L01_00478898(void);
extern void func_L01_004788D0(s32);
extern s32 func_003A4288(void);
extern void func_L01_0047DAA0_0047E738(void);
extern S_0047E680 *D_001D52FC;
extern s32 D_L01_001D8220;
extern u8 D_L01_001D672E_0047E738;
extern u8 D_L01_001D672E;
extern u32 D_001D4CEC;
__asm__(".extern D_L01_001D8220, 4");
__asm__(".extern D_L01_001D672E_0047E738, 4");

void func_L01_0047E738(void) {
    s32 n;

    func_L01_0047E680();
    func_L01_00478898();
    func_L01_004788D0(0);
    func_003A4288();
    n = *(s32 *)((u8 *)D_001D52FC + 0x1A0);
    if (n != 0) {
        n = 0x5DC;
        D_L01_001D8220 = n;
    }
    D_L01_001D8220--;
    if (D_L01_001D8220 <= 0) {
        D_L01_001D8220 = 0;
        D_L01_001D672E_0047E738 = 1;
    } else {
        D_L01_001D672E = 0;
    }
    if (D_001D4CEC & 1) {
        func_L01_0047DAA0_0047E738();
    }
}
/* localdecomp:end func_L01_0047E738 */

/* localdecomp:start func_L01_0047E7C8 */
void func_L01_0047E7C8(void) {

}
/* localdecomp:end func_L01_0047E7C8 */

/* localdecomp:start func_L01_0047E7D0 */
typedef struct {
    u8 pad0[0x50];
    s32 a50;
    u8 pad54[0xC];
    s32 a60;
    u8 pad64[0x1C];
    s32 a80;
} S_0047E7D0;
typedef struct {
    u8 pad0[0x74];
    s32 x74;
    u8 pad78[8];
    s32 x80;
    s32 x84;
} T_0047E7D0;
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0xDC];
} E_0047E7D0;

extern S_0047E7D0 D_L01_002E9F98_0047E7D0;
extern u8 D_001425C0[];
extern E_0047E7D0 D_L01_002C5600_0047E7D0[];
extern T_0047E7D0 *D_L01_001DFD18_0047E7D0;
extern int D_001D4BB4;
__asm__(".extern D_001D4BB4, 4");
extern void func_003A2750(s32);
extern void func_0039AA38(s32);
extern void func_L01_005078C0_0047E7D0(s32);
extern void func_003A92F0(s32);
extern void func_003A9108(void);
extern void func_00393168(s32, s32, s32);
extern void func_L01_0041C4A0_0047E7D0(s32);
extern void func_003A91D0(void);
extern void func_L01_005178A0_0047E7D0(s32 *);
extern void func_L01_00517830_0047E7D0(s32);
extern void func_L01_00516090_0047E7D0(s32);

void func_L01_0047E7D0(s32 a0) {
    s32 tmp;

    if (D_L01_002E9F98_0047E7D0.a50 != 0 && D_L01_002E9F98_0047E7D0.a60 != D_L01_002E9F98_0047E7D0.a50) {
        func_003A2750(1);
        func_0039AA38(((E_0047E7D0 *)((u8 *)D_L01_002C5600_0047E7D0 + D_001425C0[D_L01_002E9F98_0047E7D0.a50] * 0xF0))->x10);
        func_L01_005078C0_0047E7D0(D_L01_002E9F98_0047E7D0.a50);
        func_003A2750(1);
    }
    func_003A92F0(1);
    func_003A9108();
    D_001D4BB4 = D_L01_002E9F98_0047E7D0.a80;
    func_00393168(0, D_L01_001DFD18_0047E7D0->x74, 0);
    func_L01_0041C4A0_0047E7D0(2);
    if (D_L01_001DFD18_0047E7D0->x80 != 0) {
        func_L01_0041C4A0_0047E7D0(3);
    }
    if (D_L01_001DFD18_0047E7D0->x84 != 0) {
        func_L01_0041C4A0_0047E7D0(4);
    }
    func_003A91D0();
    func_003A92F0(1);
    tmp = 0;
    func_L01_005178A0_0047E7D0(&tmp);
    func_L01_00517830_0047E7D0(tmp);
    func_L01_00516090_0047E7D0(a0);
}
/* localdecomp:end func_L01_0047E7D0 */

INCLUDE_ASM("asm/levels", func_L01_0047E908);

/* localdecomp:start func_L01_0047EA90 */
extern S_47A458 D_L01_002E9F98;


extern u8 D_L01_002E9FC4[];
extern u8 D_L01_002E9FE8[];
extern T_0047B230 D_L01_001E15E0;

extern T_0047B230 *func_003E6C08(void);
extern void *func_003E6DE8(T_0047B230 *);
extern void func_L01_00514DD0(void *, s32, s32);
extern void func_L01_00479280(void);
extern void func_L01_0047B420(void);
extern void func_L01_0047B990(void);
extern void func_L01_00514750(void *);
extern void func_L01_0047E908(void);

void func_L01_0047EA90(void) {
    void *q;
    s32 i;

    if ((*(S_0047B230 *)&D_L01_002E9F98).x70 == 0 && (*(S_0047B230 *)&D_L01_002E9F98).x74 != 5) {
        q = func_003E6DE8(D_L01_001E15E0.x4 != 0 ? &D_L01_001E15E0 : func_003E6C08());
        for (i = 0; i < 35; i++) {
            if (q != 0) {
                func_L01_00514DD0(q, i, D_L01_002E9FC4[i]);
            }
        }
        if ((*(S_0047B230 *)&D_L01_002E9F98).x74 != 10) {
            func_L01_00479280();
            func_L01_0047B420();
            func_L01_0047B990();
        }
    }
    func_L01_00514750(D_L01_002E9FE8);
    func_L01_0047E908();
}
/* localdecomp:end func_L01_0047EA90 */

/* localdecomp:start func_L01_0047EB88 */
__asm__(".extern D_L01_001E05F0, 8");
__asm__(".extern D_L01_001E0608, 4");
extern s32 D_L01_001E05F0;
extern s32 D_L01_001E0608;
extern s32 D_L01_0047DF40[];
extern s32 D_L01_0047E4B0[];
extern s32 D_L01_0047E330[];
extern s32 D_L01_0047E548[];
s32 func_L01_00515FB8_0047EB88(void *a0, void *a1, void *a2, void *a3, void *a4, s32 a5);

void *func_L01_0047EB88(void) {
    if (D_L01_001E0608 == 0) {
        func_L01_00515FB8_0047EB88(&D_L01_001E05F0, D_L01_0047DF40, D_L01_0047E4B0, D_L01_0047E330, D_L01_0047E548, 0);
        D_L01_001E0608 = 1;
    }
    return &D_L01_001E05F0;
}
/* localdecomp:end func_L01_0047EB88 */

/* localdecomp:start func_L01_0047EBE0 */
__asm__(".extern D_L01_001E0610_0047EBE0, 8");
__asm__(".extern D_L01_001E0628_0047EBE0, 4");
extern s32 D_L01_001E0610_0047EBE0;
extern s32 D_L01_001E0628_0047EBE0;
extern void func_L01_0047E7D0(s32);
extern void func_L01_0047E7C8_0047EBE0(void);
extern void func_L01_0047EA90(void);
extern void func_L01_0047E548_0047EBE0(void);
s32 func_L01_00515FB8_0047EBE0(void *a0, void *a1, void *a2, void *a3, void *a4, s32 a5);

void *func_L01_0047EBE0(void) {
    if (D_L01_001E0628_0047EBE0 == 0) {
        func_L01_00515FB8_0047EBE0(&D_L01_001E0610_0047EBE0, func_L01_0047E7C8_0047EBE0, func_L01_0047EA90, func_L01_0047E7D0, func_L01_0047E548_0047EBE0, 0);
        D_L01_001E0628_0047EBE0 = 1;
    }
    return &D_L01_001E0610_0047EBE0;
}
/* localdecomp:end func_L01_0047EBE0 */

/* localdecomp:start func_L01_0047EC38 */
typedef struct {
    u8 pad0[0x50];
    s32 a50[8];
} S_0047EC38;
typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padC[0xF0 - 0xC];
} E_0047EC38;
extern S_0047EC38 D_L01_002E9F98_0047EC38;
extern E_0047EC38 D_L01_002C5600_0047EC38[];
extern u8 D_001425C0[];

void func_L01_0047EC38(s32 a0) {
    if (a0 != 0) {
        D_L01_002E9F98_0047EC38.a50[((E_0047EC38 *)((u8 *)D_L01_002C5600_0047EC38 + D_001425C0[a0] * 0xF0))->x8] = a0;
    }
}
/* localdecomp:end func_L01_0047EC38 */

/* localdecomp:start func_L01_0047EC88 */
extern void func_L01_0047ECB8_0047EC88();
extern void func_L01_0047ECB0_0047EC88();

 
void func_L01_0047EC88(void) {
    func_L01_0047ECB0_0047EC88();
    func_L01_0047ECB8_0047EC88();
}
/* localdecomp:end func_L01_0047EC88 */

/* localdecomp:start func_L01_0047ECB0 */
void func_L01_0047ECB0(void) {

}
/* localdecomp:end func_L01_0047ECB0 */

/* localdecomp:start func_L01_0047ECB8 */
void func_L01_0047ECB8(void) {

}
/* localdecomp:end func_L01_0047ECB8 */

/* localdecomp:start func_L01_0047ECC0 */
extern S_0047E680 *D_001D52FC;
extern s32 D_L01_001D82B4_0047ECC0;
__asm__(".extern D_L01_001D82B4_0047ECC0, 4");
__asm__(".extern D_L01_001D8290_0047ECC0, 4");
extern s32 D_L01_001D8290_0047ECC0[] __attribute__((section(".sdata")));
extern u8 D_001426E0[];
extern u8 D_001D5470[10] __attribute__((section(".sdata")));
extern void func_0039EF28(void);
extern void func_003A5348(s32, s32, s32);
extern void *func_L01_0047EBE0_0047ECC0(void);
extern void *func_L01_0047FE28_0047ECC0(void);
extern void func_L01_00517748_0047ECC0(void *);
extern void func_L01_00516090_0047ECC0(void *);

void func_L01_0047ECC0(void) {
    s32 pad = D_001D52FC->w1C4;

    if (pad & 0xF0A0) {
        if (pad == D_L01_001D8290_0047ECC0[D_L01_001D82B4_0047ECC0]) {
            D_L01_001D82B4_0047ECC0++;
            if (D_L01_001D8290_0047ECC0[D_L01_001D82B4_0047ECC0] == -1) {
                if (D_001426E0[0xC1] != 0) {
                    D_001426E0[0xC1] = 0;
                    func_0039EF28();
                    D_001D5470[9] = 0;
                } else {
                    D_001426E0[0xC1] = 1;
                    func_0039EF28();
                    D_001D5470[9] = 1;
                }
                func_003A5348(4, 0, 0);
                D_L01_001D82B4_0047ECC0 = 0;
                func_L01_00517748_0047ECC0(func_L01_0047EBE0_0047ECC0());
                func_L01_00516090_0047ECC0(func_L01_0047FE28_0047ECC0());
            }
        } else {
            D_L01_001D82B4_0047ECC0 = 0;
            if (pad == D_L01_001D8290_0047ECC0[0]) {
                D_L01_001D82B4_0047ECC0 = 1;
            }
        }
    }
}
/* localdecomp:end func_L01_0047ECC0 */

/* localdecomp:start func_L01_0047EDB0 */
void func_L01_0047EDB0(void) {

}
/* localdecomp:end func_L01_0047EDB0 */

/* localdecomp:start func_L01_0047EDB8 */
void func_L01_0047EDB8(void) {

}
/* localdecomp:end func_L01_0047EDB8 */

/* localdecomp:start func_L01_0047EDC0 */
extern Chunk_0047EDC0 D_L01_001E0630[1];

void func_L01_0047EDC0(s32 param)
{
    u32 key1 = (*(S_0047EDC0 *)&D_L01_002E9F98).key1;
    u32 key2 = (*(S_0047EDC0 *)&D_L01_002E9F98).key2;
    s32 idx, lim;
    s32 n1, n3, n4;

    if (!param) {
        n1 = 1;
        n3 = 0;
        n4 = 0;
    } else {
        n1 = 3;
        n3 = 2;
        n4 = 1;
    }
    idx = 0;
    lim = n1;
    while (idx < lim) {
        D_L01_001E0630[idx].flags = 0;
        D_L01_001E0630[idx].key = key1;
        key1 += 0x12C00;
        idx++;
    }
    lim += 1;
    while (idx < lim) {
        D_L01_001E0630[idx].flags = 0;
        D_L01_001E0630[idx].key = key2;
        key2 += 0x12C00;
        idx++;
    }
    lim += n3;
    while (idx < lim) {
        D_L01_001E0630[idx].key = key1;
        D_L01_001E0630[idx].flags = 1;
        key1 += 0x4F000;
        idx++;
    }
    lim += n4;
    while (idx < lim) {
        D_L01_001E0630[idx].key = key2;
        D_L01_001E0630[idx].flags = 1;
        key2 += 0x4F000;
        idx++;
    }
    while (idx < 7) {
        D_L01_001E0630[idx].flags = 0;
        D_L01_001E0630[idx].key = 0;
        idx++;
    }
}
/* localdecomp:end func_L01_0047EDC0 */
