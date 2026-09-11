PSE em Ação:

Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola

Tema aplicado: Prevenção ao uso de álcool e outras drogas Disciplina / Projeto: Atividade Extensionista Prática (AEP) — UNICESUMAR Cursos: Engenharia de Software e Análise e Desenvolvimento de Sistemas Ano: 2026

Sobre o projeto:

O PSE em Ação é um sistema em linguagem C, executado em terminal, que apoia uma equipe intersetorial fictícia (IntegraPSE) — profissionais das secretarias de saúde e educação, coordenadores escolares e profissionais de referência — a planejar, registrar e acompanhar ações de prevenção ao uso de álcool e outras drogas realizadas em escolas participantes do Programa Saúde na Escola (PSE).

O sistema trabalha exclusivamente com dados fictícios e informações coletivas sobre as ações realizadas (nunca dados individuais ou identificáveis de estudantes), preservando a privacidade dos adolescentes atendidos.

Problema de pesquisa:

Como uma aplicação desenvolvida em linguagem C pode auxiliar uma equipe escolar e de saúde a planejar, registrar e acompanhar ações de prevenção ao uso de álcool e outras drogas no âmbito do PSE, apresentando informações claras sobre a execução dessas ações e preservando a privacidade dos estudantes?

Objetivo geral:

Desenvolver um sistema em linguagem C, executado em terminal, que permita a uma equipe intersetorial planejar, registrar e acompanhar ações de prevenção ao uso de álcool e outras drogas realizadas em escolas participantes do PSE, consolidando informações coletivas sem armazenar dados sensíveis ou identificáveis de estudantes.

Objetivos específicos:

Estruturar um cadastro de ações de prevenção contendo código, escola, data prevista, público-alvo, responsável, quantidade prevista de participantes e situação da ação.
Implementar mecanismos de busca por código, escola ou tema.
Disponibilizar a atualização da situação de cada ação (planejada, realizada ou cancelada), com registro da quantidade efetiva de participantes.
Gerar um resumo consolidado com o número de ações por situação, total de participantes atendidos e percentual de participação.
Validar as entradas do usuário (códigos duplicados, campos obrigatórios vazios, quantidades negativas e opções inexistentes no menu).
Escopo

Está no escopo: registro e acompanhamento coletivo das ações do eixo de prevenção ao uso de álcool e drogas do PSE.

Está fora do escopo: cadastro de dados individuais de estudantes, diagnóstico ou triagem, prescrição de tratamento, interface gráfica, banco de dados persistente e acesso via web.

Requisitos

O levantamento completo de requisitos funcionais (RF01–RF06) e não funcionais (RNF01–RNF04) está detalhado no documento da primeira entrega, em docs/.

Estrutura do repositório
.
├── docs/
│   ├── PSE_em_Acao_Prevencao_Alcool_Drogas.docx   # Documento escrito da 1ª entrega
│   ├── fluxograma_geral.png                       # Fluxograma geral do sistema (menu)
│   └── fluxograma_cadastro.png                    # Fluxograma detalhado do cadastro de ação
├── src/                                            # Código-fonte em C (a partir da 2ª entrega)
└── README.md

A pasta src/ ainda não contém código-fonte nesta primeira entrega — a implementação em C começa a partir da Sprint 3, conforme o planejamento de sprints do documento.

Como compilar e executar

A ser detalhado a partir da etapa de implementação (Sprint 3 em diante), quando o código-fonte em C for adicionado ao repositório.

Previsão de uso, uma vez implementado:

bash
gcc -o pse_em_acao src/*.c
./pse_em_acao
Planejamento (sprints)
Sprint	Período	Atividades
Sprint 1	Semana 1	Levantamento do problema, definição do tema, escopo, usuários e requisitos.
Sprint 2	Semana 2	Modelagem: fluxogramas geral e detalhado, estruturas de dados e assinaturas de funções em C.
Sprint 3	Semana 3	Implementação de cadastro, listagem e validações de entrada.
Sprint 4	Semana 4	Implementação de pesquisa e atualização de situação.
Sprint 5	Semana 5	Implementação do resumo geral e testes integrados.
Sprint 6	Semana 6	Testes finais, revisão de código, documentação técnica e organização do repositório.

Detalhes completos de riscos do projeto e mitigação estão na seção 3.6 do documento em docs/.


Nome:

Luiz Eduardo santos Silva

Romulo Sotti Demito

Lucas Pescaroli Bastos


Status do projeto

🟡 Em desenvolvimento — 1ª entrega concluída (documento escrito, fundamentação, modelagem e planejamento). Implementação em C prevista a partir da Sprint 3.
