# 🛒Sistema de Gerenciamento de Filas de Supermercado

Sistema desenvolvido em C para gerenciar filas de atendimento em um supermercado, com suporte a prioridades e múltiplos caixas.

## 📝Estrutura do Projeto

O projeto está organizado nos seguintes arquivos:

- `main.c`: Ponto de entrada do programa, implementa o menu principal
- `cliente.h/c`: Define e implementa a estrutura Cliente e suas operações
- `caixa.h/c`: Define e implementa a estrutura Caixa e gerenciamento dos caixas  
- `fila.h/c`: Implementa a fila com prioridade para clientes
- `lista.h/c`: Implementa lista encadeada para histórico de atendimentos

## ⚙️Funcionalidades

- Cadastro de clientes com prioridade (1-alta, 2-média, 3-baixa)
- Atendimento de clientes respeitando prioridades
- Gerenciamento de 5 caixas (abrir/fechar)
- Realocação automática de clientes ao fechar caixa
- Histórico de atendimentos por caixa
- Visualização do status dos caixas e filas

## 🧩 Estruturas de Dados

O projeto utiliza as seguintes estruturas:

| Estrutura | Implementação | Descrição |
|-----------|---------------|-----------|
| Fila com Prioridade | Lista encadeada ordenada | Gerencia clientes por ordem de prioridade |
| Lista de Histórico | Lista encadeada simples | Armazena registros de atendimentos por caixa |
| Array de Caixas | Vetor estático | Mantém os 5 caixas do sistema |

## ✅Compilação e Execução

O projeto utiliza Makefile para automação do build:

| Comando | Função |
|---------|--------|
| `make` | Compila o projeto |
| `make run` | Executa o programa |
| `make clean` | Remove arquivos objetos |