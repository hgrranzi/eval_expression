# eval_expression

A simple math expression calculator

## Status

COMPLETED

## Description

This programm takes as argument a characters string representing an arithmetic expression and prints its calculated result. The calculation can be done with integer values only.

<table>
  <tr>
    <td> <b>Supported characters</b> </td> <td> Digits 0-9 <br>
                                                Space <br>
                                                Round brackets <br>
                                                Math operators </td>
  </tr>
  <tr>
    <td> <b>Supported operators</b> </td> <td> <b>+</b> Addition <br>
                                               <b>-</b> Subtraction <br>
                                               <b>/</b> Division <br>
                                               <b>*</b> Multiplication <br>
                                               <b>%</b> Modulo </td>
  </tr>
  <tr>
    <td> <b>External functions</b> </td> <td> write, malloc, free </td>
  </tr>
</table>

The programm ends and displays Error if any unsupported characther or division by zero occurred. <br>
The behavior is undefined if the evaluation results in overflow of 32-bits integer.
