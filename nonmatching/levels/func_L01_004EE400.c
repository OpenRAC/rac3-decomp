/* Near miss: func_L01_004EE400 (open-rac-engine names it hero_strafe_walk), in
 * src/levels/shared/L01_004E7338.c (@ps2as). Checked with tools/check.py at level 01: 4 words.
 * What still differs: retail loads move_angle (lwc1 0x1A0) before the move vector (lq 0x190)
 * and stores the angle (swc1 0x1438) before the vector (sq 0x1420, in the jal's delay slot);
 * gcc's sched2 puts the lq/sq first because the later `lbu $v0` (critter test) gives the lq one
 * more dependent. Source order, s128/Vec4/struct copies and a struct for the hero all give the
 * same bytes; a separate pointer to the lock-on block fixes the order but costs a register.
 */
extern u8 D_001A4BE0[];
extern void func_0038CB00(void *a0);
extern void func_L01_004EE388(void);
void func_L01_004EE400(void) {
    u8 *h = D_001A4BE0;
    u8 *g;
    f32 scale;
    *(s128 *)(h + 0x1420) = *(s128 *)(h + 0x190);
    *(f32 *)(h + 0x1438) = *(f32 *)(h + 0x1A0);
    func_0038CB00(h + 0x144C);
    func_0038CB00(h + 0x144E);
    scale = 1.0f;
    if (*(u8 *)(h + 0x25E4) == 0) {
        if (*(u8 *)(h + 0x1437) == 0) {
            *(s16 *)(h + 0x144E) = 3;
            if (*(s16 *)(h + 0x144C) != 0) {
                scale = 0.0f;
            }
        } else if (*(u8 *)(h + 0x1437) == 1) {
            *(s16 *)(h + 0x144C) = 3;
            if (*(s16 *)(h + 0x144E) != 0) {
                scale = (3.0f - (f32)*(s16 *)(h + 0x144E)) / 3.0f;
            }
        }
    }
    g = D_001A4BE0;
    *(f32 *)(g + 0x1B4) *= scale;
    func_L01_004EE388();
    *(f32 *)(g + 0x1A8) = 0.0f;
    *(f32 *)(g + 0x1A4) = 0.0f;
}
