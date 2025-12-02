USE falls_car;

INSERT INTO seguro(nome,cobert_avariada,cobert_perda_total,compensacao_CO2,valor) VALUES ("Seguro Padrão",TRUE,TRUE,TRUE,59.99); --demais coberturas são Falsas por padrão(default)

SELECT * FROM seguro WHERE valor<89.50;

UPDATE FROM seguro
SET nome="Seguro Padrão Plus"
SET valor=89.50
WHERE nome="Seguro Padrão";

DELETE FROM seguro WHERE valor<100.00;
