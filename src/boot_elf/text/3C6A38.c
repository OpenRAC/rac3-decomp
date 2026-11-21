#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

typedef int Q_3C1130 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C1130;
typedef struct { f32 v[3]; } F3_3C1130;
typedef struct { u8 p0[0x10]; V_3C1130 f10; u8 p20[0x14]; u16 f34; u8 p36[0x8A]; u8 fC0[0x30]; V_3C1130 fF0; } O_3C1130;
typedef struct {
    V_3C1130 f0; V_3C1130 f10; V_3C1130 f20; u8 p30[0x18];
    f32 f48[3]; f32 f54[3]; f32 f60[3]; f32 f6C[3]; f32 f78[3]; f32 f84[3]; f32 f90[3]; f32 f9C[3];
} C_3C1130;
extern const F3_3C1130 D_001D91F0;
extern const F3_3C1130 D_001D9200;
extern const F3_3C1130 D_001D9210;
extern const F3_3C1130 D_001D9220;
extern const F3_3C1130 D_001D9230;
extern const F3_3C1130 D_001D9240;
extern void func_0038D3E0(void *, void *, void *);
extern f32 func_00382918(void);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C6A38);
