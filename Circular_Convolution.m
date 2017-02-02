sequences = [{'x[n]: '},{'h[n]: '}];
x=[];
h=[];
for s=1:length(sequences)
    disp(sequences(s))
    disp(strcat({'Enter length of '},sequences(s)))
    l(s) = input('l: ');
    seq=zeros(1,l(s));
    disp('Enter the type of sequence: ') 
    disp('"e" for exponential; ')
    disp('"u" for unit step; ')
    disp('"r" for user input; ')
    f = input('Enter type of function: ','s')
    if f=='r'
        for i=1:l(s)
            seq(i)=input(strcat('seq(',num2str(i),'): '));
        end
    else if f=='e'
            prompt = 'Enter Base value: ';
            a=input(prompt)
            for i=1:l(s)
                seq(i)=a^i;
            end
        end
    end
    if f=='u'
        seq = ones(1,l(s));
    end
    if s==1
            x=seq;
    else
            h=seq;
    end
end
hr=[];
lh = length(h);
lx = length(x);
for i=1:lh
    hr(i)=h(lh-i+1);
end
yconv=zeros(1,lx+lh-1);
xpad=[zeros(1,lx+2*(lh-1))];
for i=1:lx+2*(lh-1)
    xpad(i)=x(mod(i,lx)+1);
end
for i=1:length(yconv)
    for j=1:lh
        yconv(i)=yconv(i)+xpad(i+j-1)*hr(j);
    end
end
subplot(221)
stem(x,'m')
xlabel('First Input Sequence')
ylabel('Magnitude')
xlim([0,length(x)+1]);
ylim([0,max(x)+1]);
subplot(222)
stem(h)
xlabel('Second Input Sequence')
ylabel('Magnitude')
xlim([0,length(h)+1]);
ylim([0,max(h)+1]);
subplot(212)
stem(yconv,'g')
xlabel('Linear Convolution')
ylabel('Magnitude')
xlim([0,length(yconv)+1]);
ylim([0,max(yconv)+1]);
