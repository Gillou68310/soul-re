.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel INSTANCE_InstanceGroupNumber
/* 22EEC 800326EC E8FFBD27 */  addiu      $sp, $sp, -0x18
/* 22EF0 800326F0 1400BFAF */  sw         $ra, 0x14($sp)
/* 22EF4 800326F4 1000B0AF */  sw         $s0, 0x10($sp)
/* 22EF8 800326F8 1C00828C */  lw         $v0, 0x1C($a0)
/* 22EFC 800326FC 00000000 */  nop
/* 22F00 80032700 0000438C */  lw         $v1, 0x0($v0)
/* 22F04 80032704 00000000 */  nop
/* 22F08 80032708 80006230 */  andi       $v0, $v1, 0x80
/* 22F0C 8003270C 05004010 */  beqz       $v0, .L80032724
/* 22F10 80032710 21800000 */   addu      $s0, $zero, $zero
/* 22F14 80032714 1400828C */  lw         $v0, 0x14($a0)
/* 22F18 80032718 00000000 */  nop
/* 22F1C 8003271C 00804230 */  andi       $v0, $v0, 0x8000
/* 22F20 80032720 0100502C */  sltiu      $s0, $v0, 0x1
.L80032724:
/* 22F24 80032724 20006230 */  andi       $v0, $v1, 0x20
/* 22F28 80032728 07004010 */  beqz       $v0, .L80032748
/* 22F2C 8003272C 00000000 */   nop
/* 22F30 80032730 1400828C */  lw         $v0, 0x14($a0)
/* 22F34 80032734 00000000 */  nop
/* 22F38 80032738 00204230 */  andi       $v0, $v0, 0x2000
/* 22F3C 8003273C 02004014 */  bnez       $v0, .L80032748
/* 22F40 80032740 00000000 */   nop
/* 22F44 80032744 02001036 */  ori        $s0, $s0, 0x2
.L80032748:
/* 22F48 80032748 1C00828C */  lw         $v0, 0x1C($a0)
/* 22F4C 8003274C 00000000 */  nop
/* 22F50 80032750 0000428C */  lw         $v0, 0x0($v0)
/* 22F54 80032754 00000000 */  nop
/* 22F58 80032758 40004230 */  andi       $v0, $v0, 0x40
/* 22F5C 8003275C 07004010 */  beqz       $v0, .L8003277C
/* 22F60 80032760 00000000 */   nop
/* 22F64 80032764 1400828C */  lw         $v0, 0x14($a0)
/* 22F68 80032768 00000000 */  nop
/* 22F6C 8003276C 00404230 */  andi       $v0, $v0, 0x4000
/* 22F70 80032770 02004014 */  bnez       $v0, .L8003277C
/* 22F74 80032774 00000000 */   nop
/* 22F78 80032778 04001036 */  ori        $s0, $s0, 0x4
.L8003277C:
/* 22F7C 8003277C 1C00828C */  lw         $v0, 0x1C($a0)
/* 22F80 80032780 00000000 */  nop
/* 22F84 80032784 0000428C */  lw         $v0, 0x0($v0)
/* 22F88 80032788 00000000 */  nop
/* 22F8C 8003278C 10004230 */  andi       $v0, $v0, 0x10
/* 22F90 80032790 07004010 */  beqz       $v0, .L800327B0
/* 22F94 80032794 00000000 */   nop
/* 22F98 80032798 1400828C */  lw         $v0, 0x14($a0)
/* 22F9C 8003279C 00000000 */  nop
/* 22FA0 800327A0 00104230 */  andi       $v0, $v0, 0x1000
/* 22FA4 800327A4 02004014 */  bnez       $v0, .L800327B0
/* 22FA8 800327A8 00000000 */   nop
/* 22FAC 800327AC 10001036 */  ori        $s0, $s0, 0x10
.L800327B0:
/* 22FB0 800327B0 1C00848C */  lw         $a0, 0x1C($a0)
/* 22FB4 800327B4 00000000 */  nop
/* 22FB8 800327B8 0000828C */  lw         $v0, 0x0($a0)
/* 22FBC 800327BC 00000000 */  nop
/* 22FC0 800327C0 01004230 */  andi       $v0, $v0, 0x1
/* 22FC4 800327C4 03004010 */  beqz       $v0, .L800327D4
/* 22FC8 800327C8 0D80053C */   lui       $a1, %hi(D_800D0814)
/* 22FCC 800327CC FDC90008 */  j          .L800327F4
/* 22FD0 800327D0 08001036 */   ori       $s0, $s0, 0x8
.L800327D4:
/* 22FD4 800327D4 2400848C */  lw         $a0, 0x24($a0)
/* 22FD8 800327D8 83F7020C */  jal        strcmp
/* 22FDC 800327DC 1408A524 */   addiu     $a1, $a1, %lo(D_800D0814)
/* 22FE0 800327E0 04004010 */  beqz       $v0, .L800327F4
/* 22FE4 800327E4 FDFF0224 */   addiu     $v0, $zero, -0x3
/* 22FE8 800327E8 24800202 */  and        $s0, $s0, $v0
/* 22FEC 800327EC FEFF0224 */  addiu      $v0, $zero, -0x2
/* 22FF0 800327F0 24800202 */  and        $s0, $s0, $v0
.L800327F4:
/* 22FF4 800327F4 21100002 */  addu       $v0, $s0, $zero
/* 22FF8 800327F8 1400BF8F */  lw         $ra, 0x14($sp)
/* 22FFC 800327FC 1000B08F */  lw         $s0, 0x10($sp)
/* 23000 80032800 0800E003 */  jr         $ra
/* 23004 80032804 1800BD27 */   addiu     $sp, $sp, 0x18
.size INSTANCE_InstanceGroupNumber, . - INSTANCE_InstanceGroupNumber
