// near miss: retail stores the $gp register value itself (daddu a1,$gp,$0) at +8; C `&D_1DC8B0` gives addiu a1,$gp,0 (or lui/addiu for an array). Rest (12-byte entry, id<0 uses table +0xC with id&0x7FFFFFFF, else +0x14; table reloaded after stores) structure is as below.
typedef struct { s32 a; s32 b; void *c; } E_00121B70;
typedef struct { u8 pad0[0xC]; E_00121B70 *neg; E_00121B70 *pos; } T_00121B70;
extern T_00121B70 D_153158;
extern s32 D_1DC8B0;
void func_00121B70(s32 id, s32 a, s32 b) {
    if (id < 0) {
        id &= 0x7FFFFFFF;
        D_153158.neg[id].b = b; D_153158.neg[id].a = a; D_153158.neg[id].c = &D_1DC8B0;
    } else {
        D_153158.pos[id].b = b; D_153158.pos[id].a = a; D_153158.pos[id].c = &D_1DC8B0;
    }
}
