#include <unity.h>
#include <cmdproc.h>

void setUp(void){
    return;
}
void tearDown(void){
    return;
}
/* Funcao para testar a inserçao de elementos no array de tamanho 10 
    no 11º elemento a saída passa a -1*/
void test_cmdproc_StringFull(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    /* o array tem tamanho 10
    Inserimos 10 elementos e ao enserir o 11 dá FULL saída a -1*/
    TEST_ASSERT_EQUAL_INT(-1,newCmdChar('#'));
   
}

/*Verificar se string esta vazia*/
void test_cmdproc_StringEmpty(void){
    TEST_ASSERT_EQUAL_INT(-1,cmdProcessor());
}


/*verificar Formato da string se o primeiro elemento da string inserida corresponde ao # 
e se termina com elemento !*/
void test_cmdproc_StringFormat(void){
    /* começar por # */
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(-4,cmdProcessor());
    /* Terminar com ! */
    resetCmdString();
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(-4,cmdProcessor());
}

/* Inserçao de comando P com CS correto */
void test_cmdproc_PCScerto(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('P'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('5'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('6'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('P'+'1'+'5'+'6')%129));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(0,cmdProcessor());
}

/* Inserçao de comando P com CS errado */
void test_cmdproc_PCSerrado(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('P'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('5'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('6'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('P'+'1'+'2'+'6')%129));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-3,cmdProcessor());
}

/* Inserçao de comando S com CS certo */
void test_cmdproc_SCScerto(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('S')%129));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(0,cmdProcessor());
}

/* Inserçao de comando S com CS errado */
void test_cmdproc_SCSerrado(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('A')%129));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-3,cmdProcessor());
}

/* Inserçao de comando aleatorio*/
void test_cmdproc_NoCommand(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('D'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('5'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('6'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('D'+'1'+'2'+'6')%129));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-2,cmdProcessor());
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('D'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('D')%129));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-2,cmdProcessor());
}

/* comando P incompleto*/
void test_cmdproc_Pinc(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('P'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('5'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('P'+'1'+'5'+'6')%129));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-1,cmdProcessor());
}

/* comando s incompleto*/
void test_cmdproc_Sinc(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-1,cmdProcessor());
}

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_cmdproc_StringFull);
    resetCmdString();
    RUN_TEST(test_cmdproc_StringEmpty);
    resetCmdString();
    RUN_TEST(test_cmdproc_StringFormat);
    resetCmdString();
    RUN_TEST(test_cmdproc_PCScerto);
    resetCmdString();
    RUN_TEST(test_cmdproc_PCSerrado);
    resetCmdString();
    RUN_TEST(test_cmdproc_SCScerto);
    resetCmdString();
    RUN_TEST(test_cmdproc_SCSerrado);
    resetCmdString();
    RUN_TEST(test_cmdproc_NoCommand);
    resetCmdString();
    RUN_TEST(test_cmdproc_Pinc);
    resetCmdString();
    RUN_TEST(test_cmdproc_Sinc);

    return UNITY_END();
}