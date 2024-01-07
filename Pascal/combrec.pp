program combrec;

var
	ch:char;

function combinacao(n,p:integer):integer;
	function combn(n:integer):integer;
	begin
		if n=p then
		begin
			combn:=1;
		end
		else
		begin
			combn:=combn(n-1)*(n div (n-p));
		end;	
		writeln(n,' ',p,' ',combn);
	end;
	function combp(p:integer):integer;
	begin
		if p=0 then
		begin
			combp:=1;
		end
		else if p=1 then
		begin
			combp:=n;
		end
		else
		begin
			combp:=combp(p-1)*((n-p+1) div p);
			//writeln(combp);
		end;	
	end;

begin
	combinacao:=combn(n);
end;

procedure prog();
var
	n,p:integer;
begin
	write('n = ');
	readln(n);
	write('p = ');
	readln(p);
	writeln(#10,'combinacao( ',n,' , ',p,' )  =  ',combinacao(n,p));
end;

begin
	repeat
	begin
		prog();
		write(#10,'Deseja continuar(caracter s)? ');
		readln(ch);
	end;
	until ch<>'s';
end.
	
