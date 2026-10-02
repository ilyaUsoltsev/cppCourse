#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

enum reg_t {
  A = 0,
  B = 1,
  C = 2,
  D = 3,
};

enum opcode_t {
  MOVI = 0,
  ADD = 8,
  SUB = 9,
  MUL = 10,
  DIV = 11,
  IN = 0x30,
  OUT = 0x31,
};

union operands_t {
  int imm;
  enum reg_t reg;
  struct {
    enum reg_t rx, rs;
  } regs;
};

struct instruction_t {
  enum opcode_t opc;
  union operands_t ops;
};

int encode(struct instruction_t *instr) {
  int encoded = 0;
  encoded |= (instr->opc & 0x3F) << 26;

  switch (instr->opc) {
    case MOVI:
      return instr->ops.imm & 0x7F;
      break;
    case ADD:
    case SUB:
    case MUL:
    case DIV:
        encoded = instr->opc << 4 | (instr->ops.regs.rx) << 2 |
        (instr->ops.regs.rs);
      break;
    case IN:
    case OUT:
      encoded = instr->opc << 2 | (instr->ops.reg);
      break;
    default:
      fprintf(stderr, "Unknown opcode: %d\n", instr->opc);
      abort();
  }

  return encoded;
}


static enum reg_t parse_reg(const char* context) {
    char token[16];

    if (scanf("%15s", token) != 1) {
        printf("ERROR");
        exit(EXIT_SUCCESS);
    }

    size_t length = strlen(token);

    bool valid_shape =
        length == 1 ||
        (length == 2 && token[1] == ',');

    char letter = token[0];

    bool valid_register =
        letter >= 'A' &&
        letter <= 'D';

    if (!valid_shape || !valid_register) {
        printf("ERROR");
        exit(EXIT_SUCCESS);
    }

    return (enum reg_t)(letter - 'A');
}

static int parse_movi() {
    struct instruction_t instr;
    instr.opc = MOVI;
    
    if (scanf("%d", &instr.ops.imm) != 1 || instr.ops.imm < 0 || instr.ops.imm > (1 << 7)) {
        printf("ERROR");
      exit(EXIT_SUCCESS);
    }
    
    return encode(&instr);
}

static int parse_add() {
    struct instruction_t instr;
    instr.opc = ADD;
    instr.ops.regs.rx = parse_reg("ADD");
    instr.ops.regs.rs = parse_reg("ADD");

    return encode(&instr);
}

static int parse_sub() {
    struct instruction_t instr;
    instr.opc = SUB;
    instr.ops.regs.rx = parse_reg("SUB");
    instr.ops.regs.rs = parse_reg("SUB");

    return encode(&instr);
}

static int parse_mul() {
    struct instruction_t instr;
    instr.opc = MUL;
    instr.ops.regs.rx = parse_reg("MUL");
    instr.ops.regs.rs = parse_reg("MUL");

    return encode(&instr);
}

static int parse_div() {
    struct instruction_t instr;
    instr.opc = DIV;
    instr.ops.regs.rx = parse_reg("DIV");
    instr.ops.regs.rs = parse_reg("DIV");

    return encode(&instr);
}

static int parse_in() {
    struct instruction_t instr;
    instr.opc = IN;
    instr.ops.reg = parse_reg("IN");

    return encode(&instr);
}

static int parse_out() {
    struct instruction_t instr;
    instr.opc = OUT;
    instr.ops.reg = parse_reg("OUT");

    return encode(&instr);
}

int main() {
  char mnemonic[16] = {0};

  while ((scanf("%15s", mnemonic)) == 1) {
    int encoded = 0;

    if (strcmp(mnemonic, "MOVI") == 0) {
      encoded = parse_movi();
      printf("0x%x", encoded);
    } else if (strcmp(mnemonic, "ADD") == 0) {
      encoded = parse_add();
      printf("0x%x", encoded);   
    } else if (strcmp(mnemonic, "SUB") == 0) {
      encoded = parse_sub();
      printf("0x%x", encoded);   
    } else if (strcmp(mnemonic, "MUL") == 0) {
      encoded = parse_mul();
      printf("0x%x", encoded);   
    } else if (strcmp(mnemonic, "DIV") == 0) {
      encoded = parse_div();
      printf("0x%x", encoded);   
    } else if (strcmp(mnemonic, "IN") == 0) {
      encoded = parse_in();
      printf("0x%x", encoded);   
    } else if (strcmp(mnemonic, "OUT") == 0) {
      encoded = parse_out();
      printf("0x%x", encoded);
    } else {
      printf("ERROR");
      return 0;
    }
    printf(" ");
  }

    return 0;
}
