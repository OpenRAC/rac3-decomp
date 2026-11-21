/* functional: medium. Starts from the PAL near-miss draft (compiles; byte differences are loop register allocation and branch shape only); interval-clamp and edge-expansion blocks re-read against the asm. */
/* localdecomp:start func_L09_003BC7F0 */
typedef struct { s8 n0[4]; u8 f0[4]; s8 n1[4]; u8 f1[4]; } N_003BC7F0;
void func_L09_003BC7F0(u8 *m, E_003BC450 *goal, E_003BC450 *out, s32 *indices, s32 count, s32 *nodes, s32 *counter, vu0_v4 *target)
{
    extern s32 func_L06_004591F8(void *, void *, s32);
    extern s32 func_L09_003BD360(s32, s32, s8 *, s32 *);
    vu0_v4 temp;
    u8 *pv = *(u8 **)(m + 0x68);
    s32 *path, *testpath;
    s32 i, node, step;
    s32 near_node;
    s32 *near_path;
    f32 best, distance, dot;
    s8 *neighbors, *neighbor;
    u8 *flags, *flag;
    E_003BC450 *entry;
    best = 99999997952.0f;
    for (i = 0; i < count; i++) {
        near_path = D_L09_0021E640[indices[i]];
        *(vu0_q *)&temp = *(vu0_q *)(m + 0x10);
        near_node = func_L06_004591F8(&temp,near_path,0);
        distance = func_0038CF38(m + 0x10, (u8 *)near_path + 0x10 + near_node * 16);
        if (distance < best) {
            goal->node = near_node;
            best = distance;
            goal->id = i;
        }
    }
    best = 99999997952.0f;
    for (i = 0; i < count; i++) {
        near_path = D_L09_0021E640[indices[i]];
        *(vu0_q *)&temp = *(vu0_q *)target;
        near_node = func_L06_004591F8(&temp,near_path,0);
        distance = func_0038CF38(target, (u8 *)near_path + 0x10 + near_node * 16);
        if (distance < best) {
            goal->sub = near_node;
            best = distance;
            goal->b2 = i;
        }
    }
    testpath = D_L09_0021E640[indices[goal->id]];
    if ((goal->node == 0 || goal->node == testpath[0] - 1) &&
        *(s16 *)(pv + 0x258) == goal->node && *(f32 *)(pv + 0x25C) <= *(f32 *)(pv + 0x1C4)) {
        if (goal->node == 0) {
            neighbors = ((N_003BC7F0 *)nodes)[goal->id].n0;
            flags = ((N_003BC7F0 *)nodes)[goal->id].f0;
        } else {
            flags = ((N_003BC7F0 *)nodes)[goal->id].f1;
            neighbors = ((N_003BC7F0 *)nodes)[goal->id].n1;
        }
        entry = out;
        flag = flags; neighbor = neighbors;
        do {
            if (*neighbor != -1) {
                s32 *edgepath = D_L09_0021E640[*neighbor];
                entry->id = (*counter)++;
                entry->node = *neighbor;
                entry->b2 = *flag ? 0 : *(u8 *)edgepath - 1;
                entry->sub = entry->node == goal->b2 ? goal->sub : *flag ? *(u8 *)edgepath - 1 : 0;
                entry->parent = -1;
                if (entry->node == goal->b2) {
                    if (*flag) entry->g = goal->sub;
                    else entry->g = *(u8 *)edgepath - (u8)goal->sub - 1;
                } else entry->g = *(u8 *)edgepath;
                node = func_L09_003BD360(entry->node,entry->sub,(s8 *)goal,indices);
                entry->h = node;
                entry->f = entry->g + node;
                entry++;
            }
            flag++; neighbor++;
        } while ((s32)flag < (s32)(flags + 4));
        return;
    }
    path = D_L09_0021E640[indices[goal->id]];
    vec_sub_ab(&temp,m + 0x10,(u8 *)path + 0x10 + goal->node * 16);
    temp.z = 0.0f;
    best = func_0038CE68(m + 0xC0,&temp);
    step = -1;
    if (goal->node < path[0] - 1) step = 1;
    *(vu0_q *)&temp = *(vu0_q *)&D_L09_001D66B0;
    vec_sub_ab(&temp,m + 0x10,(u8 *)path + 0x10 + (goal->node + step) * 16);
    dot = func_0038CE68(m + 0xC0,&temp);
    out[1].node = out[0].node = goal->id;
    out[1].parent = out[0].parent = -1;
    out[0].id = (*counter)++;
    out[1].id = (*counter)++;
    if (step > 0) out[0].sub = *(u8 *)path - 1;
    else out[0].sub = 0;
    if (step > 0) out[1].sub = 0;
    else out[1].sub = *(u8 *)path - 1;
    if (best < 0.0f) {
        out[0].b2 = goal->node;
        if (dot < 0.0f) out[1].b2 = goal->node + step;
        else out[1].b2 = goal->node;
    } else {
        out[0].b2 = goal->node + step;
        if (dot < 0.0f) out[1].b2 = goal->node + step;
        else out[1].b2 = goal->node;
    }
    if (goal->id == goal->b2) {
        if (step > 0) {
            if (goal->sub < out[0].b2 || goal->sub > out[0].sub) goto second;
            out[0].sub = goal->sub;
            goto done;
        } else {
            if (goal->sub > out[0].b2 || goal->sub < out[0].sub) goto second;
            out[0].sub = goal->sub;
            goto done;
        }
second:
        {
            u8 finish = goal->sub;
            if (step < 0) {
                if ((s8)finish < out[1].b2 || (s8)finish > out[1].sub) goto done;
                out[1].sub = finish;
            } else {
                if ((s8)finish > out[1].b2 || (s8)finish < out[1].sub) goto done;
                out[1].sub = finish;
            }
        }
    }
done:
    out[0].g = abs_asm(out[0].sub - out[0].b2);
    { s32 cost = func_L09_003BD360(out[0].node,out[0].sub,(s8 *)goal,indices);
    out[0].f = out[0].g + cost;
    out[1].g = abs_asm(out[1].sub - out[1].b2);
    out[0].h = cost; }
    node = func_L09_003BD360(out[1].node,out[1].sub,(s8 *)goal,indices);
    node++;
    out[1].h = node;
    out[1].f = out[1].g + node;
}
/* localdecomp:end func_L09_003BC7F0 */
