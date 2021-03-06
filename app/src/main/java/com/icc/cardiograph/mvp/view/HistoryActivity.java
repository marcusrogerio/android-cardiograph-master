package com.icc.cardiograph.mvp.view;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageView;
import android.widget.ListView;

import com.icc.cardiograph.R;
import com.icc.cardiograph.adapter.HistoryAdapter;
import com.icc.cardiograph.bean.HeartRate;

import java.util.List;

public class HistoryActivity extends Activity {
	private ListView lvHistory;
	private ImageView ivReturn;
	private List<HeartRate> lsthistory;
	private HistoryAdapter historyAdapter;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	// TODO Auto-generated method stub
    	super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_history);
		initData();
		initComponent();
		registerListener();
    }
    private void initData(){
    	HeartRate hr = new HeartRate(this);
    	lsthistory = hr.findHeartRates();
    }
	private void initComponent() {
		lvHistory = (ListView) findViewById(R.id.lvHistory);
		ivReturn = (ImageView) findViewById(R.id.ivReturn);
		historyAdapter = new HistoryAdapter(this,lsthistory);
		lvHistory.setAdapter(historyAdapter);

	}
	private void registerListener() {
		ivReturn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				finish();
				overridePendingTransition(R.anim.left_to_right_in, R.anim.left_to_right_out);
			}
		});
	}
	@Override
	public void onBackPressed() {
		// TODO Auto-generated method stub
		super.onBackPressed();
		overridePendingTransition(R.anim.left_to_right_in, R.anim.left_to_right_out);
	}
}
