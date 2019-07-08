void dfs_visit  (int i , int len){
  for(int j = 0 ; j < n ; j++){
      if(a[i][j]){
          if(a[i][j]){
            a[i][j] = a[j][i] = 0;
            dfs_visit(j,len+1);
            a[i][j] = a[j][i] = 1;
          }
  }
  if(len > best) best = len;
}
void dfs(){
  int i;
  best = 0 ;
  for(int i = 0 ; i < n ; i++){
    dfs_visit(i,0);
  }
  cout << best << endl;
}
  
