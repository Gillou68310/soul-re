.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

.section .rodata
dlabel jtbl_80011F84
/* 2784 80011F84 942E0880 */ .word .L80082E94
/* 2788 80011F88 9C2E0880 */ .word .L80082E9C
/* 278C 80011F8C 942E0880 */ .word .L80082E94
/* 2790 80011F90 942E0880 */ .word .L80082E94
/* 2794 80011F94 8C2E0880 */ .word .L80082E8C
/* 2798 80011F98 8C2E0880 */ .word .L80082E8C
/* 279C 80011F9C 8C2E0880 */ .word .L80082E8C
/* 27A0 80011FA0 9C2E0880 */ .word .L80082E9C
/* 27A4 80011FA4 8C2E0880 */ .word .L80082E8C
/* 27A8 80011FA8 9C2E0880 */ .word .L80082E9C
/* 27AC 80011FAC 3C2E0880 */ .word .L80082E3C
/* 27B0 80011FB0 9C2E0880 */ .word .L80082E9C
/* 27B4 80011FB4 9C2E0880 */ .word .L80082E9C
/* 27B8 80011FB8 9C2E0880 */ .word .L80082E9C
/* 27BC 80011FBC 9C2E0880 */ .word .L80082E9C
/* 27C0 80011FC0 942E0880 */ .word .L80082E94
/* 27C4 80011FC4 9C2E0880 */ .word .L80082E9C
/* 27C8 80011FC8 582E0880 */ .word .L80082E58
/* 27CC 80011FCC 9C2E0880 */ .word .L80082E9C
/* 27D0 80011FD0 9C2E0880 */ .word .L80082E9C
/* 27D4 80011FD4 9C2E0880 */ .word .L80082E9C
/* 27D8 80011FD8 9C2E0880 */ .word .L80082E9C
/* 27DC 80011FDC 942E0880 */ .word .L80082E94
.size jtbl_80011F84, . - jtbl_80011F84


.section .text
/* Generated by spimdisasm 1.21.0 */

glabel MON_GetSaveInfo
/* 73508 80082D08 D8FFBD27 */  addiu      $sp, $sp, -0x28
/* 7350C 80082D0C 1400B1AF */  sw         $s1, 0x14($sp)
/* 73510 80082D10 21888000 */  addu       $s1, $a0, $zero
/* 73514 80082D14 2000BFAF */  sw         $ra, 0x20($sp)
/* 73518 80082D18 1C00B3AF */  sw         $s3, 0x1C($sp)
/* 7351C 80082D1C 1800B2AF */  sw         $s2, 0x18($sp)
/* 73520 80082D20 1000B0AF */  sw         $s0, 0x10($sp)
/* 73524 80082D24 6C01308E */  lw         $s0, 0x16C($s1)
/* 73528 80082D28 2400338E */  lw         $s3, 0x24($s1)
/* 7352C 80082D2C 2190A000 */  addu       $s2, $a1, $zero
/* 73530 80082D30 0C00428E */  lw         $v0, 0xC($s2)
/* 73534 80082D34 00000000 */  nop
/* 73538 80082D38 07004230 */  andi       $v0, $v0, 0x7
/* 7353C 80082D3C 5E0102A2 */  sb         $v0, 0x15E($s0)
/* 73540 80082D40 FF004230 */  andi       $v0, $v0, 0xFF
/* 73544 80082D44 3000638E */  lw         $v1, 0x30($s3)
/* 73548 80082D48 80100200 */  sll        $v0, $v0, 2
/* 7354C 80082D4C 21104300 */  addu       $v0, $v0, $v1
/* 73550 80082D50 0000428C */  lw         $v0, 0x0($v0)
/* 73554 80082D54 00000000 */  nop
/* 73558 80082D58 680102AE */  sw         $v0, 0x168($s0)
/* 7355C 80082D5C 26004290 */  lbu        $v0, 0x26($v0)
/* 73560 80082D60 00000000 */  nop
/* 73564 80082D64 260122A6 */  sh         $v0, 0x126($s1)
/* 73568 80082D68 0000428E */  lw         $v0, 0x0($s2)
/* 7356C 80082D6C 00000000 */  nop
/* 73570 80082D70 00804230 */  andi       $v0, $v0, 0x8000
/* 73574 80082D74 05004014 */  bnez       $v0, .L80082D8C
/* 73578 80082D78 00000000 */   nop
/* 7357C 80082D7C 24FE010C */  jal        MON_TurnOffBodySpheres
/* 73580 80082D80 00000000 */   nop
/* 73584 80082D84 650B0208 */  j          .L80082D94
/* 73588 80082D88 00000000 */   nop
.L80082D8C:
/* 7358C 80082D8C 4EFE010C */  jal        MON_TurnOnBodySpheres
/* 73590 80082D90 21202002 */   addu      $a0, $s1, $zero
.L80082D94:
/* 73594 80082D94 0000028E */  lw         $v0, 0x0($s0)
/* 73598 80082D98 0000438E */  lw         $v1, 0x0($s2)
/* 7359C 80082D9C 00C04230 */  andi       $v0, $v0, 0xC000
/* 735A0 80082DA0 25186200 */  or         $v1, $v1, $v0
/* 735A4 80082DA4 0400028E */  lw         $v0, 0x4($s0)
/* 735A8 80082DA8 0008043C */  lui        $a0, (0x8000000 >> 16)
/* 735AC 80082DAC 000003AE */  sw         $v1, 0x0($s0)
/* 735B0 80082DB0 0400438E */  lw         $v1, 0x4($s2)
/* 735B4 80082DB4 24104400 */  and        $v0, $v0, $a0
/* 735B8 80082DB8 25186200 */  or         $v1, $v1, $v0
/* 735BC 80082DBC 040003AE */  sw         $v1, 0x4($s0)
/* 735C0 80082DC0 0C00428E */  lw         $v0, 0xC($s2)
/* 735C4 80082DC4 00000000 */  nop
/* 735C8 80082DC8 42120200 */  srl        $v0, $v0, 9
/* 735CC 80082DCC 1F004230 */  andi       $v0, $v0, 0x1F
/* 735D0 80082DD0 5A0102A2 */  sb         $v0, 0x15A($s0)
/* 735D4 80082DD4 0C00428E */  lw         $v0, 0xC($s2)
/* 735D8 80082DD8 00000000 */  nop
/* 735DC 80082DDC 42150200 */  srl        $v0, $v0, 21
/* 735E0 80082DE0 07004230 */  andi       $v0, $v0, 0x7
/* 735E4 80082DE4 580102A2 */  sb         $v0, 0x158($s0)
/* 735E8 80082DE8 08004286 */  lh         $v0, 0x8($s2)
/* 735EC 80082DEC 00000000 */  nop
/* 735F0 80082DF0 D80002AE */  sw         $v0, 0xD8($s0)
/* 735F4 80082DF4 0A004296 */  lhu        $v0, 0xA($s2)
/* 735F8 80082DF8 00000000 */  nop
/* 735FC 80082DFC 480102A6 */  sh         $v0, 0x148($s0)
/* 73600 80082E00 0C00428E */  lw         $v0, 0xC($s2)
/* 73604 80082E04 00000000 */  nop
/* 73608 80082E08 C2100200 */  srl        $v0, $v0, 3
/* 7360C 80082E0C 3F004230 */  andi       $v0, $v0, 0x3F
/* 73610 80082E10 FAFF4324 */  addiu      $v1, $v0, -0x6
/* 73614 80082E14 1700622C */  sltiu      $v0, $v1, 0x17
/* 73618 80082E18 20004010 */  beqz       $v0, .L80082E9C
/* 7361C 80082E1C 0180023C */   lui       $v0, %hi(jtbl_80011F84)
/* 73620 80082E20 841F4224 */  addiu      $v0, $v0, %lo(jtbl_80011F84)
/* 73624 80082E24 80180300 */  sll        $v1, $v1, 2
/* 73628 80082E28 21186200 */  addu       $v1, $v1, $v0
/* 7362C 80082E2C 0000628C */  lw         $v0, 0x0($v1)
/* 73630 80082E30 00000000 */  nop
/* 73634 80082E34 08004000 */  jr         $v0
/* 73638 80082E38 00000000 */   nop
.L80082E3C:
/* 7363C 80082E3C FF7F023C */  lui        $v0, (0x7FFFFFFF >> 16)
/* 73640 80082E40 FFFF4234 */  ori        $v0, $v0, (0x7FFFFFFF & 0xFFFF)
/* 73644 80082E44 1800238E */  lw         $v1, 0x18($s1)
/* 73648 80082E48 BFFF0424 */  addiu      $a0, $zero, -0x41
/* 7364C 80082E4C 24186400 */  and        $v1, $v1, $a0
/* 73650 80082E50 180023AE */  sw         $v1, 0x18($s1)
/* 73654 80082E54 D80002AE */  sw         $v0, 0xD8($s0)
.L80082E58:
/* 73658 80082E58 58010292 */  lbu        $v0, 0x158($s0)
/* 7365C 80082E5C 00000000 */  nop
/* 73660 80082E60 08004014 */  bnez       $v0, .L80082E84
/* 73664 80082E64 00100224 */   addiu     $v0, $zero, 0x1000
/* 73668 80082E68 48010386 */  lh         $v1, 0x148($s0)
/* 7366C 80082E6C 480102A6 */  sh         $v0, 0x148($s0)
/* 73670 80082E70 D40003AE */  sw         $v1, 0xD4($s0)
/* 73674 80082E74 1800228E */  lw         $v0, 0x18($s1)
/* 73678 80082E78 00000000 */  nop
/* 7367C 80082E7C 80004234 */  ori        $v0, $v0, 0x80
/* 73680 80082E80 180022AE */  sw         $v0, 0x18($s1)
.L80082E84:
/* 73684 80082E84 AB0B0208 */  j          .L80082EAC
/* 73688 80082E88 17000224 */   addiu     $v0, $zero, 0x17
.L80082E8C:
/* 7368C 80082E8C AB0B0208 */  j          .L80082EAC
/* 73690 80082E90 02000224 */   addiu     $v0, $zero, 0x2
.L80082E94:
/* 73694 80082E94 AB0B0208 */  j          .L80082EAC
/* 73698 80082E98 0D000224 */   addiu     $v0, $zero, 0xD
.L80082E9C:
/* 7369C 80082E9C 0C00428E */  lw         $v0, 0xC($s2)
/* 736A0 80082EA0 00000000 */  nop
/* 736A4 80082EA4 C2100200 */  srl        $v0, $v0, 3
/* 736A8 80082EA8 3F004230 */  andi       $v0, $v0, 0x3F
.L80082EAC:
/* 736AC 80082EAC 980122AE */  sw         $v0, 0x198($s1)
/* 736B0 80082EB0 6700288A */  lwl        $t0, 0x67($s1)
/* 736B4 80082EB4 6400289A */  lwr        $t0, 0x64($s1)
/* 736B8 80082EB8 68002986 */  lh         $t1, 0x68($s1)
/* 736BC 80082EBC 5F0028AA */  swl        $t0, 0x5F($s1)
/* 736C0 80082EC0 5C0028BA */  swr        $t0, 0x5C($s1)
/* 736C4 80082EC4 600029A6 */  sh         $t1, 0x60($s1)
/* 736C8 80082EC8 0C00458E */  lw         $a1, 0xC($s2)
/* 736CC 80082ECC 2C006282 */  lb         $v0, 0x2C($s3)
/* 736D0 80082ED0 821B0500 */  srl        $v1, $a1, 14
/* 736D4 80082ED4 3F006730 */  andi       $a3, $v1, 0x3F
/* 736D8 80082ED8 2A10E200 */  slt        $v0, $a3, $v0
/* 736DC 80082EDC 11004010 */  beqz       $v0, .L80082F24
/* 736E0 80082EE0 01000624 */   addiu     $a2, $zero, 0x1
/* 736E4 80082EE4 02150500 */  srl        $v0, $a1, 20
/* 736E8 80082EE8 24104600 */  and        $v0, $v0, $a2
/* 736EC 80082EEC 02004010 */  beqz       $v0, .L80082EF8
/* 736F0 80082EF0 00000000 */   nop
/* 736F4 80082EF4 02000624 */  addiu      $a2, $zero, 0x2
.L80082EF8:
/* 736F8 80082EF8 9801238E */  lw         $v1, 0x198($s1)
/* 736FC 80082EFC 17000224 */  addiu      $v0, $zero, 0x17
/* 73700 80082F00 06006214 */  bne        $v1, $v0, .L80082F1C
/* 73704 80082F04 21202002 */   addu      $a0, $s1, $zero
/* 73708 80082F08 18000524 */  addiu      $a1, $zero, 0x18
/* 7370C 80082F0C B6FF010C */  jal        MON_PlayAnim
/* 73710 80082F10 01000624 */   addiu     $a2, $zero, 0x1
/* 73714 80082F14 C90B0208 */  j          .L80082F24
/* 73718 80082F18 00000000 */   nop
.L80082F1C:
/* 7371C 80082F1C 01FF010C */  jal        MON_PlayAnimID
/* 73720 80082F20 2128E000 */   addu      $a1, $a3, $zero
.L80082F24:
/* 73724 80082F24 2000BF8F */  lw         $ra, 0x20($sp)
/* 73728 80082F28 1C00B38F */  lw         $s3, 0x1C($sp)
/* 7372C 80082F2C 1800B28F */  lw         $s2, 0x18($sp)
/* 73730 80082F30 1400B18F */  lw         $s1, 0x14($sp)
/* 73734 80082F34 1000B08F */  lw         $s0, 0x10($sp)
/* 73738 80082F38 0800E003 */  jr         $ra
/* 7373C 80082F3C 2800BD27 */   addiu     $sp, $sp, 0x28
.size MON_GetSaveInfo, . - MON_GetSaveInfo
