#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067C948.c, which this file was cut from */
void func_L39_0067EC30(void);
void func_L39_005F1718(void);
void func_L39_0067C9C0(void);

/* localdecomp:start func_L39_0067CAC0 */
__asm__(".extern D_L39_002467DC, 4");
extern s32 D_L39_002467DC;
extern s32 D_L39_0024BB44;
extern f32 D_L39_0024BB48_0067CAC0;
__asm__(".extern D_L39_0024BB48_0067CAC0, 16");
extern s32 D_L39_0024B9C8;
extern u8 D_L39_002429AE_0067CAC0;
__asm__(".extern D_L39_002429AE_0067CAC0, 16");
extern unsigned long D_L39_00240200_0067CAC0;
__asm__(".extern D_L39_00240200_0067CAC0, 16");
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern s32 D_001A5810[];
__asm__(".extern D_L39_0024680C, 4");
extern s32 D_L39_0024680C;
extern u8 D_L39_00247A1A;
typedef struct { u8 b0; u8 b1; u8 pad[6]; s32 f8; } S_0067CAC0;
void func_L39_0067C9C0(void);
void func_L39_005A61D8(void);
void func_003A92F0(s32);
s32 func_00139E08(s32);
void func_00388138(void);
void func_L39_0058CC68(void);
void func_L39_005FCDF8(void);
void func_003A9150(void);
void func_003923D0(void);
void func_00392748(s32);
void func_L39_00597E70(void);
void func_L01_00461818(void);
void func_001959F8(void);
void func_L39_0067EC30(void);
void func_L39_005F1718(void);
void func_L39_006D8B88(void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_L39_00689420(void);
void func_L39_00689570(void);

void func_L39_0067CAC0(void) {
    D_L39_002467DC++;
    func_L39_0067C9C0();
    D_L39_0024BB44++;
    func_L39_005A61D8();
    func_003A92F0(1);
    D_L39_0024BB48_0067CAC0 = (f32)*(volatile u32 *)0x10000800 / (D_001A5810[0] != 0 ? 11520.0f : 9600.0f); /* T0_COUNT */
    func_00139E08(0);
    D_L39_002429AE_0067CAC0 = 0;
    D_L39_0024B9C8++;
    func_00388138();
    D_L39_00240200_0067CAC0 += *(volatile u32 *)0x10000800;
    *(volatile u32 *)0x10000800 = 0;
    func_L39_0058CC68();
    func_L39_005FCDF8();
    func_003A9150();
    func_003923D0();
    func_00392748(1);
    func_L39_00597E70();
    func_L01_00461818();
    func_001959F8();
    func_L39_0067EC30();
    func_L39_005F1718();
    if (D_L39_0024D760 != 0) {
        S_0067CAC0 *q;
        s32 d;
        func_L39_006D8B88(D_L39_0024D760);
        q = D_L39_0024D760;
        d = 0;
        if (q->b1 != 0) {
            d = (s32)func_00130760(func_0012DCB0(), 0x24000) - q->f8;
        }
        if (D_L39_0024680C < d && D_L39_00247A1A != 0) {
            func_L39_00689420();
        } else {
            func_L39_00689570();
        }
    }
    D_L39_002467DC--;
}
/* localdecomp:end func_L39_0067CAC0 */

/* localdecomp:start func_L39_0067CCB0 */
__asm__(".extern D_L39_002467E0, 4");
extern s32 D_L39_002467E0;
extern s32 D_L39_0024BB44;
extern f32 D_L39_0024BB48;
__asm__(".extern D_L39_0024BB48, 16");
extern s32 D_L39_0024B9C8;
extern u8 D_L39_002429AE;
__asm__(".extern D_L39_002429AE, 16");
extern unsigned long D_L39_00240200;
__asm__(".extern D_L39_00240200, 16");
extern s32 D_001A5810[];
void func_L39_005A61D8(void);
void func_003A92F0(s32);
s32 func_00139E08(s32);
void func_00388138(void);
void func_L39_0058CC68(void);
void func_L39_005FCDF8(void);
void func_003A9150(void);
void func_003923D0(void);
void func_00392748(s32);
void func_L39_00597E70(void);
void func_L01_00461818(void);

void func_L39_0067CCB0(void) {
    D_L39_002467E0++;
    func_L39_0067C9C0();
    D_L39_0024BB44++;
    func_L39_005A61D8();
    func_003A92F0(1);
    D_L39_0024BB48 = (f32)*(volatile u32 *)0x10000800 / (D_001A5810[0] != 0 ? 11520.0f : 9600.0f); /* T0_COUNT */
    func_00139E08(0);
    D_L39_002429AE = 0;
    D_L39_0024B9C8++;
    func_00388138();
    D_L39_00240200 += *(volatile u32 *)0x10000800;
    *(volatile u32 *)0x10000800 = 0;
    func_L39_0058CC68();
    func_L39_005FCDF8();
    func_003A9150();
    func_003923D0();
    func_00392748(1);
    func_L39_00597E70();
    func_L01_00461818();
    func_L39_0067EC30();
    ((s32 (*)(void))func_L39_005F1718)();
    D_L39_002467E0--;
}
/* localdecomp:end func_L39_0067CCB0 */
