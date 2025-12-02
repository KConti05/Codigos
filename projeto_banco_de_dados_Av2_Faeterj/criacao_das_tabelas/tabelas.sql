USE falls_car;

CREATE TABLE cliente (
  id INT PRIMARY KEY AUTO_INCREMENT,
  nome VARCHAR(100) NOT NULL,
  cpf_cnpj VARCHAR(14) NOT NULL, -- varchar(14) para poder receber cpf e cnpj
  email VARCHAR(100) NOT NULL,
  senha_hash VARCHAR(20) NOT NULL,
  cnh CHAR(11) NOT NULL,
  telefone CHAR(11) NOT NULL
);

CREATE TABLE funcionario (
  id INT PRIMARY KEY AUTO_INCREMENT,
  nome VARCHAR(100) NOT NULL,
  cpf CHAR(11) NOT NULL,
  email VARCHAR(100) NOT NULL,
  senha_hash VARCHAR(20) NOT NULL,
  funcao VARCHAR(50) NOT NULL
);

CREATE TABLE motorista (
  id INT PRIMARY KEY AUTO_INCREMENT,
  id_funcionario INT NOT NULL,
  nome VARCHAR(100) NOT NULL,
  cnh CHAR(11) NOT NULL,
  diaria DECIMAL(10,2) NOT NULL,
  FOREIGN KEY (id_funcionario) REFERENCES funcionario(id)
);

CREATE TABLE loja (
  id INT PRIMARY KEY AUTO_INCREMENT,
  nome VARCHAR(100) NOT NULL,
  endereco VARCHAR(100) NOT NULL,
  cidade VARCHAR(100) NOT NULL,
  uf CHAR(2) NOT NULL,
  telefone VARCHAR(14)
);

CREATE TABLE modelo (
  id INT PRIMARY KEY AUTO_INCREMENT,
  nome VARCHAR(100) NOT NULL,
  marca VARCHAR(30) NOT NULL,
  ano CHAR(10) NOT NULL,
  categoria VARCHAR(30) NOT NULL,
  preco_padrao DECIMAL(10,2) NOT NULL
);

CREATE TABLE carro (
  id INT PRIMARY KEY AUTO_INCREMENT,
  id_modelo INT NOT NULL,
  id_loja INT NOT NULL,
  placa CHAR(7) NOT NULL,
  automatico BOOLEAN DEFAULT FALSE COMMENT 'se o carro é automatico inserir TRUE',
  valor DECIMAL(10,2) NOT NULL,
  status VARCHAR(50) NOT NULL COMMENT 'livre, alocado ou em manutenção',
  FOREIGN KEY (id_modelo) REFERENCES modelo(id),
  FOREIGN KEY (id_loja) REFERENCES loja(id)
);

CREATE TABLE manutencao (
  id INT PRIMARY KEY AUTO_INCREMENT,
  id_carro INT NOT NULL,
  data_entrada DATETIME NOT NULL,
  data_saida DATETIME NOT NULL COMMENT 'armazenar data de saida prevista, caso atrase, atualizar',
  valor DECIMAL(10,2) NOT NULL,
  descricao_servicos TEXT NOT NULL,
  FOREIGN KEY (id_carro) REFERENCES carro(id)
);

CREATE TABLE seguro (
  id INT PRIMARY KEY AUTO_INCREMENT,
  nome VARCHAR(30) NOT NULL,
  cobert_avariada BOOLEAN DEFAULT FALSE COMMENT 'avariação do veiculo',
  cobert_perda_total BOOLEAN DEFAULT FALSE COMMENT 'perda total do veiculo',
  cobert_dano_terc BOOLEAN DEFAULT FALSE COMMENT'danos de terceiros ao veiculo',
  cobert_furto_roubo BOOLEAN DEFAULT FALSE COMMENT 'furto e roubo do veiculo',
  cobert_vidro_pneus BOOLEAN DEFAULT FALSE COMMENT 'vidros e pneus do veiculo',
  compensacao_CO2 BOOLEAN DEFAULT FALSE COMMENT 'compencação de emissão de CO2',
  inc_limpeza BOOLEAN DEFAULT FALSE COMMENT 'limpeza do veiculo inclusa',
  valor DECIMAL(10,2) NOT NULL
);

CREATE TABLE locacao (
  id INT PRIMARY KEY AUTO_INCREMENT,
  id_cliente INT NOT NULL,
  id_motorista INT NOT NULL,
  id_carro INT NOT NULL,
  id_loja_retirada INT NOT NULL,
  id_loja_devolucao INT NOT NULL,
  id_seguro INT NOT NULL,
  data_locacao DATETIME NOT NULL,
  data_devolucao DATETIME NOT NULL COMMENT 'armazenar data prevista, caso atrase atualizar',
  motorista_aparte BOOLEAN DEFAULT FALSE COMMENT 'se o motorista nao for o contratante, TRUE',
  status VARCHAR(50) NOT NULL COMMENT 'reservada, ocorrendo, em atraso, finalizada',
  valor_total DECIMAL(10,2) NOT NULL,
  canal VARCHAR(50) NOT NULL COMMENT 'recepção ou site',
  FOREIGN KEY (id_cliente) REFERENCES cliente(id),
  FOREIGN KEY (id_motorista) REFERENCES motorista(id),
  FOREIGN KEY (id_carro) REFERENCES carro(id),
  FOREIGN KEY (id_loja_retirada) REFERENCES loja(id),
  FOREIGN KEY (id_loja_devolucao) REFERENCES loja(id),
  FOREIGN KEY (id_seguro) REFERENCES seguro(id)
);

CREATE TABLE pagamento (
  id INT PRIMARY KEY AUTO_INCREMENT,
  id_cliente INT NOT NULL,
  data_pagamento DATETIME,
  valor_pago DECIMAL(10,2) NOT NULL,
  status VARCHAR(20) NOT NULL COMMENT 'pendente, confirmado, cancelado',
  FOREIGN KEY (id_cliente) REFERENCES cliente(id)
);

CREATE TABLE locacaoPagamento (
  id INT PRIMARY KEY AUTO_INCREMENT,
  id_locacao INT NOT NULL,
  id_pagamento INT NOT NULL,
  FOREIGN KEY (id_locacao) REFERENCES locacao(id),
  FOREIGN KEY (id_pagamento) REFERENCES pagamento(id)
);
