#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 124988.c's earlier functions (tools/port_from_us.py) */
typedef struct { s32 pad0; s32 f4; s32 f8; s32 fc; s32 f10; void *f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; s32 f2c; s32 f30; void *f34; } S_124988;
extern s32 D_0013E310[];
extern s32 D_0013E314[];
extern u8 D_00150DC0[];
extern u8 D_00150DD0[];
extern s32 func_0011EE20(void *);
extern u32 D_0013E300[4];
extern u32 D_0013E2F8;
extern void func_00124B80(u32, u32);
extern u32 func_00124A68(u32, u32, void *);
extern void func_00124A28(void);
extern void func_001249F0(void);
extern void func_0011EED0(s32 *);
extern void func_0011EEC0(s32 *);
extern char *D_0013E020;
extern int D_0013EAD8[];
extern void func_00124DA8(int a, int b);
extern void *func_00124D68(void *dst, void *src, int n);
extern int func_0011B868();
extern void func_0011EA60(char *p, s32 argc, char *s);
extern void func_00124ED0();
extern void func_00124ED0(s32);
extern void func_0011EA40(s32);
typedef struct { u32 a; u32 v; } P_124FB8;
extern void func_00124F50(u32, u32);
extern void func_00124F60(u32, void *, s32);
extern u32 func_00124FA8(u32);
extern void func_0011F0A0(s32);
extern P_124FB8 D_0013F248[];
extern u8 D_0013EAE0[];
extern u8 D_0013F220[];
typedef struct Alarm_125130 {
    struct Alarm_125130 *next;
    u8 pad4[0x40 - 4];
} Alarm_125130;
typedef struct {
    u64 f0;
    int id;
    int fC;
    int f10;
    Alarm_125130 *free;
} Timer_125130;
extern Timer_125130 D_0013F288;
extern Alarm_125130 D_157AC0[];
extern s32 func_0011A264();
extern void func_00125C68(void);
extern int func_0011EB10(int cause, void *handler, int next, void *arg);
extern int func_0011F8D8(int cause);
extern void func_00125100(int n);
extern void func_00125110(int n);
extern void func_00125120(int n);
extern int func_00125578();
int func_00124920(void);
int func_00124970(void);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125288);
