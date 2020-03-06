bool temX (int v[], x, n){
 	
    // Função que retorna True caso consiga achar um par de 
    // indices no vetor v[] que a soma seja igual a x
    // n é o tamanho do vetor
	
    int i = 0;
    int n - 1;
 	
    // Equanto i e j não tenham colidido
    while (i < j) { 
        if (v[i] + v[j] == X) 
	    return true;
        
	if (v[i] + v[j] < X)
	    i++;
        else   
	    j--;
    }

    // Caso não tenha achado nada
    return false
}
