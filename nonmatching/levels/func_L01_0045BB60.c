/* Near miss, ported from rac2-decomp's func_002B5EF8 (cross-game near pair). NEAR: retail builds 1.5707964f inline (lui/ori/mtc1) which needs @ps2as; file src/levels/shared/L01_0045A6F0.c has no @ps2as (default as gives a .lit4/gp load); with --as ps2as (information only) 71 diff: constant fixed (1.5707964f not ...965) but retail has 2 nops after the mtc1 before div.s that we do n */
typedef struct { char pad[0x68]; float angle; } Slot_002B5EF8;
typedef struct {
    char pad0[0x38];
    unsigned int flags;                  
    char pad1[0x48 - 0x3C];
    Slot_002B5EF8 *left;                 
    Slot_002B5EF8 *right;                
} Rec_002B5EF8;
extern float func_0038DB00(float, float);
extern float func_0038DAB8(float, float);

void func_L01_0045BB60(char *self, Rec_002B5EF8 *other, float x)
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