program anagramas;

var
	ch:char;
	numero:integer;
	a:array[1..50000] of string;

procedure sort(var v:array of char;n:integer);
	procedure buble(n:integer);
		procedure troca(i:integer);
			procedure swap(var x,y:char);
			var 
				tmp:char;
			begin
				tmp:=x;
				x:=y;
				y:=tmp;
			end;
		begin
			if i>=0 then
			begin
				troca(i-1);
				if ((ord(v[i]))>(ord(v[i+1]))) then
					swap(v[i],v[i+1]);
			end;
		end;
	begin
		if n>=0 then
		begin
			troca(n-1);
			buble(n-1);
		end;
	end;
begin
	buble(n-1);
end;

procedure anagrama(var v:array of char;n:integer);
var
	np:integer=0;
	s:array[1..8] of integer;
	//p:array[1..8] of char;
	p:string='';
	//q:array[1..8] of char;//guarda o anagrama anterior
	num:integer=0;
	i:integer;
	
	procedure initBol();
	var
		i:integer;
	begin
		for i:=1 to n do
			s[i]:=0;		
	end;
	
	procedure anag();
	var
		i,j,b:integer;
		procedure impr();
		var
			j:integer;
		begin
			for j:=1 to n do
				write(p[j]);
			write(' ');
			if((numero mod 15)=0) then
				writeln();
		end;
		(*function diferente():integer;
		var
			i:integer;
		begin
			diferente:=0;
			//if num=0 then
			//begin
				//writeln('nova palavra');
				//diferente:=1;
			//end
			//else
			//begin
				writeln('-----------------');
				for i:=1 to n do
				begin
					writeln(#10,p[i],' ',q[i]);
					if(ord(p[i])<>ord(q[i]))then
						diferente:=1;
				end;
			//end;
		end;*)
	begin
		for i:=1 to n do
		begin
			if s[i]=0 then
			begin
				np:=np+1;
				p[np]:=v[i-1];
				s[i]:=1;
				
				if np=n then
				begin
					writeln(p);
					(*b:=diferente();
					//writeln('b=',b,' p=',p[i],' q=',q[i]);
					if(b=1) then
					begin
						for j:=1 to n do
							q[j]:=p[j];
						impr();
						num:=1;
						numero:=numero+1;
						writeln(#10,'-----------------');
					end;
					//numero:=numero+1;
					//impr();*)
					//a[]:=
					//impr();
					num:=1;
					numero:=numero+1;
					a[numero]:=p;
				end
				else
				begin
					anag();
				end;
				
				np:=np-1;
				s[i]:=0;
			end;
		end;
	end;

begin
	numero:=0;
	initBol();
	anag();
	for i:=1 to 30000 do 
		writeln(a[i]);
end;

procedure prog();
var
	n,i:integer;
	v:array[1..8] of char;
	s:string;
begin
	repeat
	begin
		write('digite uma string de no maximo 8 letras-> ');
		readln(s);
	end;
	until length(s)<=8;
	n:=length(s);
	for i:=1 to n do
		v[i]:=s[i];
	sort(v,n);
	for i:=1 to numero do
		write(v[i],' ');
	writeln();
	anagrama(v,n);
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
