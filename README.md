# PSE em Ação

Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola — tema aplicado: **prevenção ao uso de álcool e outras drogas**.
Atividade Extensionista Prática (AEP) — UniCesumar — Engenharia de Software e Análise e Desenvolvimento de Sistemas.

Programa de terminal em linguagem C que permite à equipe intersetorial (IntegraPSE) planejar, registrar e acompanhar ações coletivas de prevenção nas escolas do Programa Saúde na Escola (PSE).
O sistema **não armazena dados individuais ou sensíveis de estudantes**; os dados ficam apenas em memória durante a execução.

## Funcionalidades (menu)

| Opção | Função |
|---|---|
| 1 | Cadastrar ação (código, escola, tema, data DD/MM/AAAA, público-alvo, responsável, quantidade prevista) |
| 2 | Listar ações |
| 3 | Pesquisar ação por código, escola ou tema |
| 4 | Atualizar situação (planejada, realizada, cancelada) |
| 5 | Registrar/corrigir participantes de ação realizada |
| 6 | Gerar resumo geral (ações por situação, participantes, percentual de participação) |
| 0 | Sair |

Validações: código duplicado ou inválido, campos vazios, data inexistente, quantidades negativas ou nulas, opção inexistente, registro inexistente e limite de 50 ações.

## Compilação e execução

Requisito: compilador C com suporte a C11 (gcc).

```bash
# Linux / macOS
gcc -std=c11 -Wall -Wextra -pedantic -o pse src/main.c   # ou: make
./pse

# Windows (MinGW)
gcc -std=c11 -o pse.exe src/main.c
pse.exe
```

## Testes

```bash
make test        # executa 23 casos de teste em pseudo-terminal (Linux/macOS; requer Python 3)
```

## Estrutura

```
src/main.c        código-fonte
tests/            testes automatizados e geradores de imagens/diagramas
docs/             documento final (.docx), roteiro do vídeo e imagens
Makefile
```

## Documentação

- `docs/PSE_em_Acao_2a_Entrega.docx`: requisitos atualizados, fluxogramas, casos de uso, testes, manual do usuário e considerações finais.
- `docs/roteiro_video.md`: roteiro do vídeo de apresentação (até 7 minutos).

## Grupo

[Nomes e RAs dos integrantes]
