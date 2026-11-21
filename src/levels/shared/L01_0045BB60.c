#include "common.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;
typedef struct { u8 pad[16]; u8 sub[248 - 16]; f32 f; } S457;
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0045BB60 */
typedef struct { char pad[0x68]; float angle; } Slot_0045BB60;
typedef struct {
    char pad0[0x38];
    unsigned int flags;                  
    char pad1[0x48 - 0x3C];
    Slot_0045BB60 *left;                 
    Slot_0045BB60 *right;                
} Rec_0045BB60;
extern float func_0038DB00(float, float);
extern float func_0038DAB8(float, float);

/* from rac2-decomp's func_002B5EF8 */
void func_L01_0045BB60(char *self, Rec_0045BB60 *other, float x)
{
    float k, w1, w2, inv, d;
    if (other->left == 0 && other->right == 0)
        return;
    if (other->flags & 0x10)
        return;
    w1 = 0.0f;
    if (other->left != 0)
        w1 = 1.0f;
    w2 = 0.0f;
    if (other->right != 0)
        w2 = 1.0f;
    inv = 1.0f / (w1 + w2);
    w1 *= inv;
    w2 *= inv;
    k = 1.5707964f;
    d = func_0038DB00(x, *(float *)(self + 0xF8));
    if (k < d)
        d = k;
    else if (d < -k)
        d = -k;
    if (*(unsigned short *)(self + 0x34) & 0x8000)
        d = -d;
    if (other->left != 0) {
        other->left->angle = func_0038DAB8(d * w1, other->left->angle);
        if (k < other->left->angle)
            other->left->angle = k;
        else if (other->left->angle < -k)
            other->left->angle = -k;
    }
    if (other->right != 0) {
        other->right->angle = func_0038DAB8(d * w2, other->right->angle);
        if (k < other->right->angle)
            other->right->angle = k;
        else if (other->right->angle < -k)
            other->right->angle = -k;
    }
}
/* localdecomp:end func_L01_0045BB60 */
