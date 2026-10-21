#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00124F20(s32);
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

/* localdecomp:start func_00124ED8 */
extern void func_0011EA60(char *p, s32 argc, char *s);
extern void func_00124ED0();

void func_00124ED8(char *name, s32 argc, char **argv) {
    char *p;
    p = func_00124DB8(name, argc, argv);
    func_00124ED0();
    func_0011EA60(p, argc, D_0013E020 + 4);
}
/* localdecomp:end func_00124ED8 */

/* localdecomp:start func_00124F20 */
extern void func_00124ED0(s32);
extern void func_0011EA40(s32);

void func_00124F20(s32 a) {
    func_00124ED0(a);
    func_0011EA40(a);
}
/* localdecomp:end func_00124F20 */
