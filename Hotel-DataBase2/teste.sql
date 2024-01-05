CREATE OR REPLACE FUNCTION ocupacaoHoteis()
RETURNS trigger
AS $$
DECLARE
    cursor_hotel CURSOR FOR
        SELECT ID_HOTEL FROM HOTEL;
    id_hotel INTEGER;
BEGIN
    OPEN cursor_hotel;
    LOOP
        FETCH NEXT FROM cursor_hotel
        INTO id_hotel;
        EXIT WHEN NOT FOUND;
         SELECT (ocupacaoHotel(id_hotel)).*;
    END LOOP;
    CLOSE cursor_hotel;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION ocupacaoHoteis1()
RETURNS TABLE(id_hotel integer, vagas_totais integer, vagas_livre integer, vagas_ocupadas integer, porcentagem numeric)
AS $$
DECLARE
    cursor_ocupacao CURSOR FOR
        SELECT O.ID_HOTEL, O.CAPACIDADE_QUARTO, R.ID_RESERVA FROM OFERTA O FULL OUTER JOIN RESERVA R ON (O.ID_OFERTA=R.ID_OFERTA)
        WHERE (O.DATA_START >= CURRENT_DATE);
    cursor_hotel CURSOR FOR
        SELECT HOTEL.ID_HOTEL FROM HOTEL;
    id_hotel INTEGER;
    oid_hotel INTEGER;
    nvagas INTEGER;
    ocupadas INTEGER;
    livres INTEGER;
    idres INTEGER;
    cquarto INTEGER;
    porcentagem NUMERIC;
BEGIN
	OPEN cursor_hotel;
    LOOP
        FETCH NEXT FROM cursor_hotel
            INTO id_hotel;
		nvagas:=0;
		ocupadas:=0;
		OPEN cursor_ocupacao;
		LOOP
		    FETCH NEXT FROM cursor_ocupacao
		        INTO cquarto,idres;
		    EXIT WHEN NOT FOUND;
			IF oid_hotel = id_hotel THEN
				IF idres IS NOT NULL THEN
				    ocupadas := ocupadas + cquarto;
				END IF;
				nvagas:=nvagas+cquarto;
			END IF;
		END LOOP;
		CLOSE cursor_ocupacao;
		livres:=nvagas-ocupadas;
		porcentagem:=((ocupadas/nvagas)*100);
		RETURN QUERY VALUES (id_hotel, nvagas, livres, ocupadas, porcentagem);
	END LOOP;
	CLOSE cursor_hotel;
END;

$$ LANGUAGE plpgsql;

-- select (ocupacaoHoteis1()).*;
-- DROP FUNCTION ocupacaoHoteis1;

