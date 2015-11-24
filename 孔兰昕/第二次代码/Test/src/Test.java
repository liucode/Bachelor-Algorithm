
public class Test{
	public static void main(String args[]) {
	    
		System.out.println("跳转次数为："+new Test().num(new int[] { 4, 6, 2, 5, 1, 3, 0, 4,
				8, 1, 5, 3, 6 }));

		
	}
	public int num(int a[]){
		int i=0;
		int ok=0;
		while(i<a.length-1){
			System.out.println(a[i]);
			
			int temp=i;
			int max=i+1;
			int j=0;
			if(a.length-i<=a[i]+1)max=a.length-1;
			else
			for(j=i+2;j-temp<=a[temp];j++){
				
				if(j>=a.length)break;
				if(a[j]+1>a[j-1])max=j;
			}
			
			i=max;
			ok++;
		}
		System.out.println(a[i]);
		return ok;
		
	}
	
}

