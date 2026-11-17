#include "common.h"

typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_001CCFD0_003AFF18;

/* localdecomp:start func_L03_003AF7F0 */
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern f32 D_001DE820_sda;
__asm__(".extern D_001DE820_sda, 4");
extern f32 D_L03_001DE824[4];
__asm__(".extern D_L03_001DE824, 16");
extern f32 D_L03_001DE828[4];
__asm__(".extern D_L03_001DE828, 16");
void func_L01_00450DE8(void *q, void *p, f32 a, f32 b, f32 c);
void func_L03_003AF7F0(void *self) {
    char *s = (char *)self;
    char *t = *(char **)(s + 0x68);
    char *q = D_L03_001DF99C + (*(int *)(t + 0x15C) << 8);
    *(f32 *)(s + 0xF8) = *(f32 *)(q + 0xF8);
    func_L01_00450DE8(q, s + 0x10, D_001DE820_sda, D_L03_001DE824[0], D_L03_001DE828[0]);
}
/* localdecomp:end func_L03_003AF7F0 */
