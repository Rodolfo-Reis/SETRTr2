/**
 * @file testapp.c
 * @brief Aplicação para teste das funcionalidades do FIFO 
 * 
 * Neste aplicação temos um menu de opções a que o utilizador pode recorrer para 
 * verificar o funcionamento do FIFO.
 * 
 * @author Rodolfo Oliveira, NºMec: 88919
 * @date 14 Março 2023
 * 
 * @bug Nenhum bug conhecido
 * 
*/
/* Includes */
#include <unity.h>
#include <cmdproc.h>

void setUp(void){
    return;
}
void tearDown(void){
    return;
}

/**
 * @brief Funcao  Unity para testar a inserçao de elementos no array de tamanho 10 até detetar array FUll
 * 
 * São inseridos 10 elementos e verificados que o retorno é 0, inserçao bem sucedida,
 * no 11º elemento o retorno é -1, string full
 * 
 * 
 * 
*/
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
/**
 * @brief Funcao  Unity erificar se string esta vazia
 * 
 * Não é inserido nenhum elemento e pedesse a verificaçao do processo
 * 
 * 
 * 
*/
/*Verificar se string esta vazia*/
void test_cmdproc_StringEmpty(void){
    TEST_ASSERT_EQUAL_INT(-1,cmdProcessor());
}

/**
 * @brief verificar Formato da string
 * 
 * se o primeiro elemento da string inserida corresponde ao # 
 *  e se termina com elemento !
 * Verifica se a string tem mais do que um # e/ou !
 * 
 * 
*/
/*verificar Formato da string se o primeiro elemento da string inserida corresponde ao # 
e se termina com elemento !*/
void test_cmdproc_StringFormat(void){
    /* começar por # */
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('P'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('0'));
    TEST_ASSERT_EQUAL_INT(-4,cmdProcessor());
    /* Terminar com ! */
    resetCmdString();
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(-4,cmdProcessor());
    /* Tem 2 #*/
    resetCmdString();
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(-4,cmdProcessor());
    /*Tem 2 ! */
    resetCmdString();
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-4,cmdProcessor());
}
/**
 * @brief Inserçao de comando P com CS correto
 * 
 * Iserimos um comando do tipo P completo e com o CS corretamente inserido
 * 
 * 
 * 
*/
/* Inserçao de comando P com CS correto */
void test_cmdproc_PCScerto(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('P'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('2'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('6'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('P'+'1'+'2'+'6')%9));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(0,cmdProcessor());
}

/**
 * @brief Inserçao de comando P com CS errado
 * 
 * Iserimos um comando do tipo P completo e com o CS incorretamente inserido
 * 
 * 
 * 
*/
/* Inserçao de comando P com CS errado */
void test_cmdproc_PCSerrado(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('P'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('5'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('6'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('P'+'1'+'2'+'6')%9));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-3,cmdProcessor());
}
/**
 * @brief Inserçao de comando S com CS certo 
 * 
 * Iserimos um comando do tipo S completo e com o CS corretamente inserido
 * 
 * 
 * 
*/
/* Inserçao de comando S com CS certo */
void test_cmdproc_SCScerto(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('S')%9));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(0,cmdProcessor());
}
/**
 * @brief Inserçao de comando S com CS errado
 * 
 * Iserimos um comando do tipo S completo e com o CS incorretamente inserido
 * 
 * 
 * 
*/
/* Inserçao de comando S com CS errado */
void test_cmdproc_SCSerrado(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('A')));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-3,cmdProcessor());
}
/**
 * @brief Inserçao de comando aleatorio
 * 
 * Iserimos um comando sem ser do tipo S ou P mas completo e com o formato certo 
 * para nao ser detetado outro erro
 * 
 * 
*/
/* Inserçao de comando aleatorio*/
void test_cmdproc_NoCommand(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('D'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('5'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('6'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('D'+'1'+'2'+'6')%9));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-2,cmdProcessor());
    resetCmdString();
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('d'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('D')%9));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-2,cmdProcessor());
}
/**
 * @brief comando P incompleto
 * 
 * Iserimos um comando do tipo P mas com formato incompleto
 * 
 * 
*/
/* comando P incompleto*/
void test_cmdproc_Pinc(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('P'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('1'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('5'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar((unsigned char)('P'+'1'+'5'+'6')%9));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-1,cmdProcessor());
}
/**
 * @brief comando S incompleto
 * 
 * Iserimos um comando do tipo S mas com formato incompleto
 * 
 * 
*/
/* comando s incompleto*/
void test_cmdproc_Sinc(void){
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('#'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('S'));
    TEST_ASSERT_EQUAL_INT(0,newCmdChar('!'));
    TEST_ASSERT_EQUAL_INT(-1,cmdProcessor());
}



/**
 * @brief Main
 * 
 * Dá Run de todos os unity testes
 * 
 * 
*/
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